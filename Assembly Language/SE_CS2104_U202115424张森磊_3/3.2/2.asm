.386     
.model flat, stdcall
 
public Scopy
public func

 S struct
	SAMID DB 9 dup(0)
	SDA   DD 0
	SDB   DD 0
	SDC   DD 0
	SF    DD 0
S ENDS
 .data
 f dd 0
 .stack 200
 .code

 Scopy proc  des:dword,sou:dword
	push esi
	push edi
	push eax
	push ebx
	mov ebx,0
	mov esi,sou
	mov edi,des
S0:
	mov eax,[esi+ebx*4]
	mov [edi+ebx*4],eax
	inc ebx
	cmp ebx,6
	jne S0
	mov al,[esi+24]
	mov [edi+24],al
	pop ebx
	pop eax
	pop edi
	pop esi
	ret
Scopy endp
func proc data:dword
	push esi
	push ebx
	mov esi,data
	mov	ebx,[esi+9]
	imul ebx,5
	sub ebx,[esi+17]
	add ebx,[esi+13]
	add	ebx,100
	shr ebx,7
	mov [esi+21],ebx
	mov f,ebx
	pop ebx
	pop esi
	ret
func endp
end