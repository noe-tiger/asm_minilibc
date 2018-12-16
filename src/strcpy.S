	global  strcpy
	section .text

strcpy:
	push rbp
	mov  rbp, rsp
	xor  rcx, rcx

loop:
	cmp  BYTE [rsi + rcx], 0
	jz   end
	mov  r8b, [rsi + rcx]
	mov  [rdi + rcx], r8b
	inc  rcx
	jmp  loop

end:
	mov  rax, rdi
	mov  rsp, rbp
	pop  rbp
	ret
