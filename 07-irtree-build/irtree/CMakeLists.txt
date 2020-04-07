#add_subdirectory(generators)
#add_subdirectory(nodes)
#add_subdirectory(tree_wrapper)

set(SOURCES generators/Label.cpp generators/Label.h generators/Temporary.cpp generators/Temporary.h tree_wrapper/SubtreeWrapper.h nodes/expressions/Expression.h nodes/BaseElement.h visitors/Visitor.h nodes/statements/Statement.h tree_wrapper/ExpressionWrapper.cpp tree_wrapper/ExpressionWrapper.h nodes/statements/ExpStatement.cpp nodes/statements/ExpStatement.h nodes/expressions/ConstExpression.cpp nodes/expressions/ConstExpression.h)

add_library(${IR_LIB} ${SOURCES})