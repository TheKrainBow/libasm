			section	.text
			global	ft_strcmp

ft_strcmp:								; strcpy(s1, s2) = strcpy(rdi, rsi)
			cmp rdi, rsi
			jz _equal
			cmp rdi, 0
			je _negatif
			cmp rsi, 0
			je _positif
			mov rcx, -1					; i = -1;

_loop:
			inc rcx						; i++;
			cmp BYTE [rdi + rcx], 0		; compare *(s1 + i) with '\0'
			je _break					; if *(s1 + i) == 0 jump to _break
			cmp BYTE [rsi + rcx], 0		; compare *(s2 + i) with '\0'
			je _break					; if *(s1 + i) == 0 jump to _break
			mov bl, BYTE [rdi + rcx]	; temp = *(s1 + i);
			sub bl, BYTE [rsi + rcx]	; temp -= *(s2 + i);
			cmp bl, 0					; compare temp with 0
			je _loop					; if bl == 0 jump to _loop

_break:
			mov bl, BYTE [rdi + rcx]	; temp = *(s1 + i);
			sub bl, BYTE [rsi + rcx]	; temp -= *(s2 + i);
			cmp bl, 0					; compare temp with 0
			jz _equal					; if bl == 0 jump to _equal
			jl _negatif					; if bl < 0 jump to _negatif

_positif:
			mov rax, 1					; set rax to 1
			ret							; return (1)

_negatif:
			mov rax, -1					; set rax to -1
			ret							; return (-1)

_equal:
			mov rax, 0					; set rax to 0
			ret							; return (0)
