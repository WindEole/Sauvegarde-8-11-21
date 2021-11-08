; size_t ft_strlen(char *str);

section .text

global ft_strlen
ft_strlen:
	xor rcx, rcx			; Set rax to 0
	xor rax, rax			; Set rax to 0

main_loop:
	cmp byte [rdi + rcx], 0	; Compare to '\0'
	jz	done				; Jump to done if equal to '\0'
	inc rcx					; Increment the iterator
	jmp main_loop			; Restart the loop

done:
	mov rax, rcx			; Set the return value to the actuel string lenght
	ret						; Return