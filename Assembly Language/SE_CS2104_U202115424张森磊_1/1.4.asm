.686     
.model flat, stdcall
 ExitProcess PROTO STDCALL :DWORD
 includelib  kernel32.lib  ; ExitProcess 在 kernel32.lib中实现
 printf          PROTO C :VARARG
 scanf			PROTO C :VARARG
 includelib  libcmt.lib
 includelib  legacy_stdio_definitions.lib
 S struct
	SAMID DB 6 dup(0)
	SDA   DD 0
	SDB   DD 0
	SDC   DD 0
	SF    DD 0
S ENDS
.DATA
	IpFmt db "%s",0ah,0dh,0
	IpFmt2 db "%s",0
	LOWF S 10 dup(<>)
	MIDF S 10 dup(<>)
	HIGHF S 10 dup(<>)
	INIT S 10 dup(<,1,2,3,>)
	STR1 DB "Please input the data",0
.STACK	200
.code
main proc c
	mov eax,0
	mov ebx,0
	mov esi,0
	mov edi,0
	mov ebp,0
L0:
	mov EAX, (S ptr INIT[ebx]).SDA
	imul EAX, 5
	add EAX, (S ptr INIT[ebx]).SDB
	sub EAX, (S ptr INIT[ebx]).SDC
	add EAX, 100
	shr EAX, 7
	mov (S ptr INIT[ebx]).SF, EAX
	cmp EAX, 100
	je L1
	jg L2
	jl L3
L1:
	mov eax, (S ptr INIT[ebx]).SDA
	mov (S ptr MIDF[esi]).SDA, eax
	mov eax, (S ptr INIT[ebx]).SDB
	mov (S ptr MIDF[esi]).SDB, eax
	mov eax, (S ptr INIT[ebx]).SDC
	mov (S ptr MIDF[esi]).SDC, eax
	mov eax, (S ptr INIT[ebx]).SF
	mov (S ptr MIDF[esi]).SF, eax
	add esi, type S
	jmp L4
L2:
	mov eax, (S ptr INIT[ebx]).SDA
	mov (S ptr HIGHF[edi]).SDA, eax
	mov eax, (S ptr INIT[ebx]).SDB
	mov (S ptr HIGHF[edi]).SDB, eax
	mov eax, (S ptr INIT[ebx]).SDC
	mov (S ptr HIGHF[edi]).SDC, eax
	mov eax, (S ptr INIT[ebx]).SF
	mov (S ptr HIGHF[edi]).SF, eax
    add edi, type S
	jmp L4
L3:
	mov eax, (S ptr INIT[ebx]).SDA
	mov (S ptr LOWF[ebp]).SDA, eax
	mov eax, (S ptr INIT[ebx]).SDB
	mov (S ptr LOWF[ebp]).SDB, eax
	mov eax, (S ptr INIT[ebx]).SDC
	mov (S ptr LOWF[ebp]).SDC, eax
	mov eax, (S ptr INIT[ebx]).SF
	mov (S ptr LOWF[ebp]).SF, eax
	add ebp, type S
	jmp L4
L4:
	add ebx, type S
	cmp ebx, 9*(type S)
	jne L0
	invoke ExitProcess,0
main endp
END
