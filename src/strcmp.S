	global  strcmp
	section .text

strcmp:
	push rbp
	mov  rbp, rsp
	xor  rcx, rcx

loop:
	mov  al , [rdi + rcx]
	mov  r8b, [rsi + rcx]
	cmp  al , 0
	je   end
	cmp  r8b, 0
	je   end
	cmp  al , r8b
	jne  end
	inc  rcx
	jmp  loop

end:
	sub   al, r8b
	movsx rax, al
	mov   rsp, rbp
	pop   rbp
	ret
