## Чекпоинт 3 (парный). Таблица символов + система типов

### Дедлайн - 18 марта 16:59

Расширяем функциональность! В прошлом чекпоинте мы создали инфраструктуру проекта, теперь необходимо соединить блоки, чтобы построить таблицу символов!

Необходимо создать Visitor, который строит две сущности:

* таблицу символов, где:
  * для методов фиксируется имена принимаемых аргументов, а также имя этого метода
  * для классов фиксируется его имя, список методов и его полей (напоминаем - все методы публичные, все поля - приватные)
  * (задание со звездочкой) - подумайте, как можно было бы обработать конструктор класса
* дерево, хранящее scope-ы всех переменных:
  * в вершине дерева находится scope
  * необходимо по имени переменной быстро находить ссылку на объект, к которому обращаемся (см. алгоритм с построением дерева scope-ов через stack)

Важные случаи, которые необходимо при этом обработать:
* Необходимо обработать shadowing-переменных (одна переменная закрывает другую)
* Переменная дважды объявляется в одном scope
* Переменная используется, хотя она не объявлена


Дополнительно необходимо реализовать систему типов. Для этого предлагается адаптировать класс, который отвечает за scope переменных, 
чтобы в значении был один из объектов:
* примитивный тип
* методы
    * принимаемые аргументы (имя - тип)
    * возвращаемое значение
* классы
    * список методов
    * список полей

Необходимо контролировать, чтобы функция именно вызывалась, и чтобы переменной класса нельзя было присвоить тип.

Пример можно найти в [примере variable scope](/05-variable-scopes). 

Успехов!