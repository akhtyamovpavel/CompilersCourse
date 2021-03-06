## Чекпоинт 6 (одиночный). Подготовка промежуточного представления LLVM

### Дедлайн - 22 апреля 16:59  


Мы уже на финишной прямой!  
Прошлые чекпоинты подготовили все необходимые структуры для ловеринга в LLVM IR. Теперь необходимо присоединить написанный вами фронтенд к инфраструктуре LLVM.  

Цель текущего чекпоинта - построить визитор, который AST дерево в промежуточное представление LLVM.  
Для этого вам необходимо, для начала, скачать и собрать LLVM.  
Вот некоторые ссылки, которые могут понадобиться при изучении архитектуры LLVM:
* [Вступительная статья о начале работы с LLVM](https://llvm.org/docs/GettingStarted.html)
* [Сборка LLVM через CMake](https://llvm.org/docs/CMake.html)

Совет: внимательно изучите флаги для сборки LLVM. Это очень тяжёлый проект, в котором нам понадобится из таргет платформ X86_64(и опционально AARCH64, как бонусная задача). 
Также у LLVM много целей сборки, большинство из которых не нужны для сборки основного проекта. Лучше всё изучить заранее, чем пересобирать повторно потом.  

После того, как вы собрали LLVM и добавили его в качестве зависимости, можно приступать к ловерингу.  
Для этого создайте нового визитора, который каждую вершину AST дерева преобразует в промежуточное представление. В этом вам поможет дерево скоупов с таблицей символов, где вы сможете находить всю необходимую информацию о преобразуемых объектах.    
Изучите основные концепции промежуточного представления: блоки, phi, вызовы функций. Практически всё необходимое можно найти в [документации к LLVM](https://llvm.org/docs/index.html). На выходе нужно получить готовый LLVM модуль, в котором будут объявлены все функции и структуры, созданные пользователем.    

Полученный LLVM IR необходимо будет выводить на экран либо сохранять в .ll файлы.  
Критерием прохождения данного чекпоинта будет возможность скомпилировать полученный IR clang-ом в объектный файл и запустить его.  

P.S. В компонентах LLVM есть также модуль Support -- полезная вещь, содержащая много разных небольших утилит. К примеру, там есть библиотека CLI. Будет неплохо, если вы замените ручной парсинг аргументов командной строки на это.
