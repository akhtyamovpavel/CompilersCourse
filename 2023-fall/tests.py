from symbol_table.memory_holder import MemoryHolder, VariableHolder
import pytest


def test_variable_holder():
    memory_holder = MemoryHolder()
    
    memory_holder.var_decl('x')
    with pytest.raises(ValueError):
        memory_holder.var_decl('x')


def test_holder_with_multiple_scopes():
    memory_holder = MemoryHolder()
    memory_holder.var_decl('x')
    memory_holder.set_var('x', 1)

    memory_holder.begin_scope()
    memory_holder.var_decl('x')
    memory_holder.set_var('x', 2)

    result = memory_holder.get_var('x')
    assert 2 == result.value


def test_holder_with_end_scope():
    memory_holder = MemoryHolder()
    memory_holder.var_decl('x')
    memory_holder.set_var('x', 1)

    memory_holder.begin_scope()
    memory_holder.var_decl('x')
    memory_holder.set_var('x', 2)

    result = memory_holder.get_var('x')
    assert 2 == result.value

    memory_holder.end_scope()

    result = memory_holder.get_var('x')
    assert 1 == result.value
