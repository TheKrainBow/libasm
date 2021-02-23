			section	.text
			global	ft_strcmp

ft_strcmp:								; strcpy(s1, s2) = strcpy(rdi, rsi)
			mov rcx, -1					; i = -1;

_loop:
			inc rcx						; i++;
			cmp BYTE [rdi + rcx], 0
			je _break
			cmp BYTE [rsi + rcx], 0
			je _break
			mov dl, BYTE [rdi + rcx]	; temp = s1(i);
			sub dl, BYTE [rsi + rcx]	; temp -= s2(i);
			cmp dl, 0					; compare temp with 0
			je _loop

_break:
			mov dl, BYTE [rdi + rcx]	; temp = s1(i);
			sub dl, BYTE [rsi + rcx]	; temp -= s2(i);
			cmp dl, 0					; compare temp with 0
			jz _equal
			jl _negatif

_positif:
			mov rax, 1
			ret

_negatif:
			mov rax, -1
			ret

_equal:
			mov rax, 0
			ret
