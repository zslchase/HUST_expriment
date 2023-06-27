.global memorycopy //声明全局函数
memorycopy:
 ldrb w3,[x1],#1 //从源字符串地址中读取
 str w3,[x0],#1 //向目的字符串地址中写
 sub x2,x2,#1 
 cmp x2,#0 //判断是否结束
bne memorycopy
ret