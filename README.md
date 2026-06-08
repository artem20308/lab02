# Лабораторная работа №2

## Цель работы
Изучение системы контроля версий Git и сервиса GitHub. Освоение основных операций: создание репозитория, коммитов, веток, Pull Request, слияния изменений и разрешения конфликтов.



# Part I

## 1) Создание репозитория

- [x] Yep


## 2) Первый коммит

- [x] git init
- [x] echo "# hello-world" > README.md
- [x] git add README.md
- [x] git commit -m "Initial commit"
- [x] git remote add origin https://github.com/artem20308/lab02.git
- [x] git push -u origin main


## 3) Создание программы Hello World
Создан файл hello_world.cpp:
```

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world" << endl;
    return 0;
}
Добавление файла и коммит:
git add hello_world.cpp
git commit -m "Added hello world program"
```

## 4) Изменение программы
Программа была изменена для ввода имени пользователя:

```
#include <iostream>

using namespace std;

int main()
{
    string name;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Hello world from " << name << endl;

    return 0;
}
```

Коммит изменений:
```zsh
git commit -am "Added username input"
```

После первого добавления файла Git начинает его отслеживать. Для уже отслеживаемых файлов достаточно использовать команду:
```zsh
git commit -am "message"
```
которая автоматически включает изменения отслеживаемых файлов в коммит.

# Part II

## 1) Создание ветки patch1
```zsh
git checkout -b patch1
```
## 2) Исправление стиля кода
Удалён оператор:
```
using namespace std;
```
Исправленный вариант:
```
#include <iostream>
#include <string>

int main()
{
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Hello world from " << name << std::endl;

    return 0;
}
```
Коммит:
```zsh
git add .
git commit -m "Fixed coding style"
```
Отправка ветки:
```zsh
git push -u origin patch1
```

## 3) Создание Pull Request
Был создан Pull Request:
patch1 -> master

## 4) Добавление комментариев
В код были добавлены комментарии:
```
// Program greeting user
```
Коммит:
```zsh
git add .
git commit -m "Added comments"
git push
```
## 5) Слияние ветки
После проверки Pull Request был выполнен merge ветки patch1 в master.
Получение изменений:
```zsh
git checkout master
git pull
```
Удаление локальной ветки:
```zsh
git branch -d patch1
```

# Part III
## 1) Создание ветки patch2
```zsh
git checkout -b patch2
```
## 2) Форматирование кода
Использована утилита clang-format:
```zsh
clang-format -style=Mozilla -i hello_world.cpp
```
Коммит:
```zsh
git add .
git commit -m "Formatted code using clang-format"
```
Отправка изменений:
```
git push -u origin patch2
```
Создан Pull Request:
patch2 -> master

## 3) Возникновение конфликта
В ветке master были изменены комментарии, после чего возник конфликт с Pull Request.
Получение обновлений:
```zsh
git checkout master
git pull
```
## 4)Разрешение конфликта
Выполнен rebase:
```zsh
git checkout patch2
git rebase master
```
После ручного исправления конфликта:
```zsh
git add hello_world.cpp
git rebase --continue
```
Изменения были отправлены принудительно:
```zsh
git push --force origin patch2
```
После этого конфликт исчез и Pull Request был успешно объединён с веткой master.

## 5) История коммитов
Проверка истории:
```zsh
git log --oneline --graph
```

# Вывод
В ходе лабораторной работы были изучены основные возможности Git и GitHub:
создание репозитория;
создание коммитов;
работа с удалённым репозиторием;
создание веток;
создание Pull Request;
слияние изменений;
разрешение конфликтов с использованием rebase;
форматирование исходного кода с помощью clang-format.

