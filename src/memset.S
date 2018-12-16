	global  memset
	section .text

memset:
	push rbp
	mov  rbp, rsp
	mov  rax, rdi
	xor  rcx, rcx

loop:
	cmp  rdx, rcx
	jz   end
	mov  [rax], sil
	inc  rcx
	inc  rax
	jmp  loop

end:
	mov  rax, rdi
	mov  rsp, rbp
	pop  rbp
	ret
