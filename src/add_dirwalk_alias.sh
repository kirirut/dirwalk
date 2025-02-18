#!/bin/zsh
alias_line='function dirwalk() { /home/user/build/dirwalk "$1" "$2"; }' # Определение алиаса(указать путь к исполняемому файлу)
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