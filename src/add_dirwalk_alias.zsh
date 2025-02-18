#!/bin/zsh
# Проверяем, передан ли аргумент (путь к исполняемому файлу)
if [ -z "$1" ]; then
    echo "Ошибка: Не указан путь к исполняемому файлу dirwalk."
    echo "Использование: $0 /путь/к/dirwalk"
    exit 1
fi
# Определение алиаса с использованием переданного пути
alias_line="function dirwalk() { $1 \"\$1\" \"\$2\"; }"

# Проверка, существует ли уже такой алиас в .zshrc
if ! grep -Fxq "$alias_line" ~/.zshrc; then
    # Если алиаса нет, добавить его в .zshrc
    echo "$alias_line" >> ~/.zshrc
    echo "Алиас dirwalk добавлен в ~/.zshrc"
else
    echo "Алиас dirwalk уже существует в ~/.zshrc"
fi
# Применяем изменения
source ~/.zshrc