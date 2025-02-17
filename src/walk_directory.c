#include "dirwalk.h"

void walk_directory(const char *dir_path, int show_links, int show_dirs, int show_files, int sort) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("opendir");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {//Parent catalog or this catalog
            continue;
        }
        process_entry(dir_path, entry, show_links, show_dirs, show_files, sort);
    }

    closedir(dir);
}
