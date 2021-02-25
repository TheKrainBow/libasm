			section	.text
			global	ft_strdup
			extern	ft_strlen, malloc, ft_strcpy

ft_strdup:				;ft_strdup(str) = ft_strdup(rdi)
			push rdi
			call ft_strlen
			pop rdi
			push rdi
			mov rdi, rax
			call malloc wrt ..plt
			pop rdi
			mov rsi, rdi
			mov rdi, rax
			call ft_strcpy
			ret
