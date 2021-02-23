			section	.text
			global	ft_strlen

ft_strlen:							; rdi = arg0 = str
			xor rax, rax			; i = 0
			cmp rdi, 0				; compare str with NULL
			je end					; return if str == NULL
			sub rax, 1				; i--

_loop:
			inc rax					; i++
			cmp BYTE [rdi + rax], 0	; compare str[i] with \0
			jne _loop				; if not \0 loop again

end:
			ret						; return i
