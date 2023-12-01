import llvmlite.ir as ll

fntype = ll.FunctionType(ll.IntType(32), [])



module = ll.Module()
printf_type = ll.FunctionType(
    ll.IntType(32), [ll.IntType(8).as_pointer()],
    var_arg=True
)

foo_type = ll.VoidType(
    
)

printf = ll.Function(module, printf_type, name='printf')

func = ll.Function(module, fntype, name='main')
bb_entry = func.append_basic_block()

builder = ll.IRBuilder()
builder.position_at_end(bb_entry)

stackint = builder.alloca(ll.IntType(32))
builder.store(ll.Constant(stackint.type.pointee, 123), stackint)
myint = builder.load(stackint)

addinstr = builder.add(myint, myint)
mulinstr = builder.mul(addinstr, ll.Constant(ll.IntType(32), 123))
pred = builder.icmp_signed('<', addinstr, mulinstr)


arg = "World\0"
c_str_val = ll.Constant(ll.ArrayType(ll.IntType(8), len(arg)),
                        bytearray(arg.encode("utf8")))
c_str = builder.alloca(c_str_val.type)
builder.store(c_str_val, c_str)

voidptr_ty = ll.IntType(8).as_pointer()
fmt_arg = builder.bitcast(c_str, voidptr_ty)

builder.call(printf, [fmt_arg])

builder.ret(mulinstr)

# bb_block = func.append_basic_block()
# builder.position_at_end(bb_block)

# bb_exit = func.append_basic_block()

# pred = builder.trunc(addinstr, ll.IntType(1))
# builder.cbranch(pred, bb_block, bb_exit)

# builder.position_at_end(bb_exit)
# builder.ret(myint)

print(module)