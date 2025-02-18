
# Dirwalk

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/kirirut/dirwalk.git
    ```

2. Enter the repository directory:

    ```bash
    mkdir build
    cd dirwalk/build
    ```

3. Build the project using `CMake`:

    ```bash
    cmake ..
    make
    ```

After building the utility, you can use the `dirwalk` command to traverse directories:

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

---

## Alias for zsh

To create an alias for the `dirwalk` command in `zsh`, add the following to your `~/.zshrc`:

```bash
function dirwalk() {
  /home/user/build/dirwalk "$1" "$2"
}
```

Then, run:

```bash
source ~/.zshrc
```
Also you can run `ass_dirwalk_alias.sh`.But you need to change path in 

```bash
alias_line='function dirwalk() { /home/user/build/dirwalk "$1" "$2"; }'
```

to your path for dirwalk.