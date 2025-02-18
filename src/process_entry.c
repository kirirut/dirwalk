#include "dirwalk.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <locale.h>

// Функция для сравнения строк (используется в qsort)
int compare_strings(const void *a, const void *b) {
    return strcoll(*(const char **)a, *(const char **)b);
}

// Функция для обработки одной записи
void process_entry(const char *dir_path, struct dirent *entry, int show_links, int show_dirs, int show_files, int sort) {
    char full_path[1024];
    snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

    struct stat statusbuff;
    if (lstat(full_path, &statusbuff) == -1) {
        perror("lstat");
        return;
    }

    int is_link = S_ISLNK(statusbuff.st_mode);
    int is_dir = S_ISDIR(statusbuff.st_mode);
    int is_file = S_ISREG(statusbuff.st_mode);

    if ((show_links && is_link) || (show_dirs && is_dir) || (show_files && is_file)) {
        if (!sort) {
            // Выводим путь только если сортировка отключена
            printf("%s\n", full_path);
        }
    }

    if (is_dir) {
        walk_directory(full_path, show_links, show_dirs, show_files, sort);
    }
}


