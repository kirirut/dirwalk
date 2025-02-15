#include "dirwalk.h"

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
        printf("%s\n", full_path);
    }

    if (is_dir) {
        walk_directory(full_path, show_links, show_dirs, show_files, sort);
    }
}
