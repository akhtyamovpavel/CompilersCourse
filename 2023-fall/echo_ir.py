import llvmlite.ir as ll

fntype = ll.FunctionType(ll.IntType(32), []) # main: ((), int)


module = ll.Module()
printf_type = ll.FunctionType(
    ll.IntType(32), [ll.IntType(8).as_pointer()],
    var_arg=True
)

printf = ll.Function(module, printf_type, name='printf')
scanf = ll.Function(module, printf_type, name='scanf')

func = ll.Function(module, fntype, name='main')

bb_entry = func.append_basic_block()
builder = ll.IRBuilder()
builder.position_at_end(bb_entry)

arg = "%d\n\0"
int_string_val = ll.Constant(ll.ArrayType(ll.IntType(8), len(arg)),
                        bytearray(arg.encode("utf8")))

scanf_arg = "%d\0"

scanf_string_val = ll.Constant(
    ll.ArrayType(ll.IntType(8), len(scanf_arg)), bytearray(scanf_arg.encode("utf-8"))
)

int_string = builder.alloca(int_string_val.type)

scanf_string = builder.alloca(scanf_string_val.type)

builder.store(int_string_val, int_string) # Storing "%d\n\0" in memory
builder.store(scanf_string_val, scanf_string)

charptr_ty = ll.IntType(8).as_pointer()
fmt_arg = builder.bitcast(int_string, charptr_ty)
scanf_fmt_arg = builder.bitcast(scanf_string, charptr_ty)



## Calling scanf
n = builder.alloca(ll.IntType(32))
factorial = builder.alloca(ll.IntType(32))

builder.store(ll.Constant(ll.IntType(32), 1), factorial)

builder.call(scanf, [scanf_fmt_arg, n])

bb_cond = func.append_basic_block()
bb_while_body = func.append_basic_block()
bb_after = func.append_basic_block()
builder.branch(bb_cond)
builder.position_at_end(bb_cond)

n_loaded = builder.load(n)

signed = builder.icmp_signed('>', n_loaded, ll.Constant(ll.IntType(32), 0))

builder.cbranch(signed, bb_while_body, bb_after)
builder.position_at_end(bb_while_body)

factorial_loaded = builder.load(factorial)
output_factorial = builder.mul(factorial_loaded, n_loaded)
builder.store(output_factorial, factorial)
output = builder.add(n_loaded, ll.Constant(ll.IntType(32), -1))
builder.store(output, n)

builder.branch(bb_cond)
builder.position_at_end(bb_after)



##
factorial_loaded = builder.load(factorial)
builder.call(printf, [fmt_arg, factorial_loaded])

builder.ret(ll.Constant(ll.IntType(32), 0))
with open('file.ll','w') as fp:
    fp.write(str(module))
# print(module)


