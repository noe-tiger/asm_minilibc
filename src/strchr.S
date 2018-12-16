	global  strchr
	global  index
	section .text

index:
strchr:
	push rbp
	mov  rbp, rsp
	push rdi
	xor  rcx, rcx

loop:
	cmp  BYTE [rdi], sil
	jz   found
	cmp  BYTE [rdi], 0
	jz   not_found
	inc  rdi
	jmp  loop

not_found:
	mov  rax, 0
	jmp  end

found:
	mov  rax, rdi
	jmp  end

end:
	pop  rdi
	mov  rsp, rbp
	pop  rbp
	ret
