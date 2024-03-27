#include <iostream>
#include <string>
#include <vector>


class Type {
public:
    std::string type;
};

Type OUR_INT {.type = "int"};
Type OUR_FLOAT {.type = "float"};

class Function: public Type {
 public:
    Type* return_type;
    std::vector<Variable> arguments;
    Function(
        Type* return_type,
        std::vector<Variable> arguments
    ): return_type(return_type), arguments(arguments) {}
};

struct Variable {
    std::string name;
    Type* type;
};

class Class: public Type {
 public:
    std::vector<Variable> fields;
    std::vector<Function*> methods;

    Class() {}
    Class(
        std::vector<Variable> fields,
        std::vector<Function*> methods
    ): fields(fields), methods(methods)
     {}
};

int main() {
    Variable a;

    a.name = "a";
    a.type = &OUR_INT;

    Variable argc;
    argc.name = "argc";
    argc.type = &OUR_INT;

    Variable main_fn;
    main_fn.name = "main";
    main_fn.type = new Function{
        &OUR_INT, std::vector<Variable>{
            argc
        }
    };

    Variable class_fn;

    class_fn.name = "Foo";
    class_fn.type = new Class{
        std::vector<Variable>{a},
        std::vector<Function*>{}
    };

}
