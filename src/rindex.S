	global  strrchr
	global  rindex
	section .text

rindex:
strrchr:
	push rbp
	mov  rbp, rsp
	xor  rcx, rcx

init:
	cmp  BYTE [rdi + rcx], 0
	jz   loop
	inc  rcx
	jmp  init

loop:
	cmp  BYTE [rdi + rcx], sil
	jz   found
	cmp  rcx, 0
	jz   not_found
	dec  rcx
	jmp  loop

not_found:
	mov  rax, 0
	jmp  end

found:
	mov  rax, rdi
	add  rax, rcx
	jmp  end

end:
	mov  rsp, rbp
	pop  rbp
	ret
