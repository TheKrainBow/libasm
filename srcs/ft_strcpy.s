			section	.text
			global	ft_strcpy

ft_strcpy:					; strcpy(dest, src) = strcpy(rdi, rsi)
			mov rbx, 0		; i = 0;
			sub rbx, 1

_loop:
			inc rbx
			mov dl, BYTE [rsi + rbx]
			mov BYTE [rdi + rbx], dl
			cmp BYTE [rsi + rbx], 0
			jnz _loop

_end:
			mov rax, rdi	; set dest as return value
			ret				; return dest;
