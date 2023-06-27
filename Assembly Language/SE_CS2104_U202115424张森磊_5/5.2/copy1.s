.global memorycopy
memorycopy:
ldp x3,x4,[x1],#16 //ldp 指令将 x1 向上加 16 个字节后存放到 x3 和 x4 中
stp x3,x4,[x0],#16
sub x2,x2,#16
cmp x2,#0
bne memorycopy
ret