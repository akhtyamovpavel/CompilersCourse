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
* Список чекпоинтов
    - [01. Одиночный. AST](/milestones/milestones-2021/01-ast.md)
    - [01. Парный. AST + locations](/milestones/milestones-2021/01-ast-locations.md)
    - [02. Одиночный. Visitors](/milestones/milestones-2021/02-visitors.md)
    - [02. Парный. Visitors + подготовка семантики](/milestones/milestones-2021/02-visitors-table.md)
    

### Сдача заданий
Сдавать задание на почту: compilers2021-checkpoints@akht.pl

На почту кидаем номер checkpoint-a, ссылку на github

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
