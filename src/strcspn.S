	global  strcspn
	section .text

strcspn:
	push rbp
	mov  rbp, rsp
	xor  rcx, rcx
	mov  rdx, rdi
	jmp  loop

check_loop:
	cmp  BYTE [r8], 0
	je   restart
	mov  al, [rdx]
	cmp  [r8], al
	je   end
	inc  r8
	jmp  check_loop

loop:
	cmp  BYTE [rdx], 0
	jz   end
	mov  r8, rsi
	jmp  check_loop

restart:
	inc  rcx
	inc  rdx
	jmp  loop

end:
	mov  rax, rcx
	mov  rsp, rbp
	pop  rbp
	ret
