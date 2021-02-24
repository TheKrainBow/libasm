			section	.text
			global	ft_strdup
			extern	ft_strlen, malloc

ft_strdup:				;ft_strdup(str) = ft_strdup(rdi)
			push rdi
			call ft_strlen
			pop rdi
			push rdi
			mov rdi, rax
			call malloc
			pop rdi
			mov rcx, -1

_loop:
			inc rcx
			mov dl, BYTE [rdi + rcx]
			mov BYTE [rax + rcx], dl
			cmp BYTE [rdi + rcx], 0
			je _loop
			inc rcx
			mov BYTE [rax + rcx],  0
			ret
