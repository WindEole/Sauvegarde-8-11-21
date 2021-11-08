;	int		ft_strcmp(char *s1, char *s2);

section .text

global ft_strcmp
ft_strcmp:
	xor rax, rax
	xor rbx, rbx
	xor rcx, rcx

.loop:
	mov al, byte[rdi + rcx]
	mov bl, byte[rsi + rcx]

	cmp al, 0 
	je .end

	cmp al, bl
	jne .end

	inc	rcx
	jmp .loop

.end:
	sub rax, rbx
	ret
