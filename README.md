# CompilersCourse

![Docker build](https://img.shields.io/docker/cloud/build/akhtyamovpavel/compilers_course_image) ![Docker Pulls](https://img.shields.io/docker/pulls/akhtyamovpavel/compilers_course_image)

Курс "Языки программирования и теории компиляции" ФПМИ МФТИ, 2 курс.

## Содержание

* [Грамматика](/reqs-draft.md)
* Список семинаров
    - [01. Лексический анализатор](/01-scanners)
    - [02. Синтаксический анализатор](/02-parsers)
    - [03. Построение AST-дерева](/03-parsers-with-ast)
    - [04. Интерпретатор через Visitor](/04-visitors)
    - [05. Таблицы символов](/05-variable-scopes)
    - [06. Механизмы вызова функций](/06-function-calls)
    - [07. Построение дерева IR](/07-irtree-build)
    - [08. Оптимизация дерева IR](/08-irtree-optimizations)
* Список чекпоинтов:
    * Одиночные:
        - [01. AST](/milestones/milestones-2021/01-ast.md)
        - [02. Visitors](/milestones/milestones-2021/02-visitors.md)
        - [03. Подготовка семантики](/milestones/milestones-2021/03-one-symbols.md)
        - [04. Дерево scope-ов](/milestones/milestones-2021/04-scope-tree.md)
        - [05. Система типов](/milestones/milestones-2021/05-one-type-checking.md)
        - [06. Промежуточное представление LLVM](/milestones/milestones-2021/06-one-llvm-IR.md)
        - [07. Создание исполняемого файла](/milestones/milestones-2021/07-one-llvm-executable.md)
    * Парные:
        - [01. AST + locations](/milestones/milestones-2021/01-ast.md)
        - [02. Visitors + подготовка семантики](/milestones/milestones-2021/02-visitors-table.md)
        - [03. Дерево scope-ов + Система Типов](/milestones/milestones-2021/03-pair-symbol-table-types.md)
        - [04. Обработка функций + ошибок](/milestones/milestones-2021/04-pair-functions-errors.md)
        - [05. IR-tree](/milestones/milestones-2021/05-pair-ir-builder.md)
    

### Сдача заданий
Сдавать задание на почту: compilers2021-checkpoints@akht.pl

На почту кидаем номер checkpoint-a, ссылку на github

### Flow работы в проекте

* В ветке main/master находится работающая версия кода, в нее будут сливать изменения кураторы
* Для разработки проекта создается ветка dev, в которой выполняется разработка
* После того, как вы считаете, что определенную часть задания выполнили, создаете отдельную ветку checkpoint_x (x=1,2,3) из ветки dev, создаете pull request из ветки checkpoint_x в ветку main/master, добавляете ревьюера на pull request
* Если ревьюер попросил сделать изменения, то вы делаете изменения в ветке checkpoint_x и вливаете ее в dev, НЕ СЛИВАЯ при этом ветку в main/master
* В описании pull request-а пишете списком (добавляете в README.md) список изменений, который произошел в новой версии проекта (от одного чекпоинта к другому)


## Сборка Docker контейнера
Ссылка на image - https://hub.docker.com/r/akhtyamovpavel/compilers_course_image

Скачивание образа:
```
docker pull akhtyamovpavel/compilers_course_image
```
Сборка образа:
```
docker build -t akhtyamovpavel/compilers_course_image .
```
