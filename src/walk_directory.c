#include "dirwalk.h"

void walk_directory(const char *dir_path, int show_links, int show_dirs, int show_files, int sort) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("opendir");
        return;
    }

    // Динамический массив для хранения путей
    char **paths = NULL;
    size_t paths_count = 0;
    size_t paths_capacity = 0;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Пропускаем "." и ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Формируем полный путь
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        // Обрабатываем запись
        process_entry(dir_path, entry, show_links, show_dirs, show_files, sort);

        // Если сортировка включена, сохраняем путь в массив
        if (sort) {
            // Увеличиваем массив, если необходимо
            if (paths_count >= paths_capacity) {
                paths_capacity = paths_capacity == 0 ? 1 : paths_capacity * 2;
                paths = realloc(paths, paths_capacity * sizeof(char *));
                if (!paths) {
                    perror("realloc");
                    closedir(dir);
                    return;
                }
            }

            // Сохраняем путь
            paths[paths_count] = strdup(full_path);
            if (!paths[paths_count]) {
                perror("strdup");
                closedir(dir);
                return;
            }
            paths_count++;
        }
    }

    closedir(dir);

    // Если сортировка включена, сортируем и выводим пути
    if (sort) {
        qsort(paths, paths_count, sizeof(char *), compare_strings);
        for (size_t i = 0; i < paths_count; i++) {
            printf("%s\n", paths[i]);
            free(paths[i]); // Освобождаем память
        }
        free(paths); // Освобождаем массив
    }
}