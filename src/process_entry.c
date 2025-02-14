#include "dirwalk.h"
#define PATH_MAX 1000
void process_entry(const char *path, const struct dirent *entry) {
    char full_path[PATH_MAX];
    struct stat st;
    snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
    if (lstat(full_path, &st) == -1) {
        perror("lstat");
        return;
    }
    printf("%s\n", full_path);
}