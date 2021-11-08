section .text

global ft_strcpy
ft_strcpy:
	push rbx
	push rcx

	mov rax, rdi				; rdi: register destination index (1 param)
	mov rbx, rsi				; rsi: register source index (2 param)
	
	xor rcx, rcx				; rcx: register count index (iterator)

main_loop:
	mov dl, byte [rsi + rcx]	; dl is the lower 8 bits of rdx.
	mov [rax + rcx], byte dl
	cmp byte dl, 0
	jz done
	inc rcx
	Jmp main_loop

done:
	pop rbx
	pop rcx
	ret
