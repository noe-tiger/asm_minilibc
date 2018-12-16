	global  strstr
	section .text

strstr:
	push rbp
	mov  rbp, rsp
	jmp  init

reset:
	cmp  al,  0
	je   not_found
	inc  rdi

init:
	mov  al,  [rdi]
	mov  al,  [rsi]
	xor  rcx, rcx

loop:
	mov  al,  [rdi + rcx]
	mov  r8b, [rsi + rcx]
	cmp  r8b,  0
	jz   found
	cmp  al,  r8b
	jne  reset
	inc  rcx
	jmp  loop

found:
	mov  rax, rdi
	jmp  end

not_found:
	xor  rax, rax
	jmp  end

end:
	mov  rsp, rbp
	pop  rbp
	ret
