#include "dirwalk.h"

int main(int argc, char *argv[]) {
    const char *dir_path = (argc > 1) ? argv[1] : "./";
    walk_directory(dir_path);
    return 0;
}