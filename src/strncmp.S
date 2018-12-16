	global  strncmp
	section .text

strncmp:
	push rbp
	mov  rbp, rsp
	mov  rcx, 0

loop:
	mov  al , [rdi + rcx]
	mov  r8b, [rsi + rcx]
	cmp  al , r8b
	jne  end
	cmp  al , 0
	je   end
	cmp  r8b, 0
	je   end
	cmp  rdx, rcx
	je   end
	inc  rcx
	jmp  loop

end:
	sub   al, r8b
	movsx rax, al
	mov   rsp, rbp
	pop   rbp
	ret
