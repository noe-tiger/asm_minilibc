	global  strcasecmp
	section .text

strcasecmp:
	push rbp
	mov  rbp, rsp
	xor  rcx, rcx
	jmp  check_left

low_left:
	add  al,  32
	jmp  check_right

low_right:
	add  r8b, 32
	jmp  loop

check_left:
	mov  al,  [rdi + rcx]
	cmp  al,  65
	jl   check_right
	cmp  al,  90
	jl   low_left

check_right:
	mov  r8b, [rsi + rcx]
	cmp  r8b, 65
	jl   loop
	cmp  r8b, 90
	jl   low_right

loop:
	cmp  al , 0
	je   end
	cmp  r8b, 0
	je   end
	cmp  al , r8b
	jne  end
	inc  rcx
	jmp  check_left

end:
	sub   al, r8b
	movsx rax, al
	mov   rsp, rbp
	pop   rbp
	ret
