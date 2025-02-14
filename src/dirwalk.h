#ifndef DIRWALK_H
#define DIRWALK_H
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
void process_entry(const char *path, const struct dirent *entry);
void walk_directory(const char *dir_path);
#endif