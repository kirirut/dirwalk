
# Dirwalk

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/kirirut/dirwalk.git
    ```

2. Enter the repository directory:

    ```bash
    cd dirwalk
    ```

3. Build the project using `CMake`:

    ```bash
    cmake ..
    make
    ```

After building the utility, you can use the `dirwalk` command to travelse directories:

```bash
./dirwalk <directory_path> <options>
```

---

## Arguments

- `<directory_path>`: The path to the directory you want to traverse.
- `<options>`: Options for filtering and sorting.

---

## Available Options

- `-l`: Show only symbolic links (`-type l`).
- `-d`: Show only directories (`-type d`).
- `-f`: Show only regular files (`-type f`).
- `-s`: Sort the output according to `LC_COLLATE`.

---

## Requirements

- Linux/Unix-like operating system (tested on Ubuntu)
- `gcc` or `clang` compiler (`sudo apt install gcc`)
- `cmake` utility for building the project (`sudo apt install cmake`)
