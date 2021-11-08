%include "libasm.s"

section .text
global ft_write
extern __errno_location

ft_write:
	mov rax , sys_write
	syscall       					; app system
	
	cmp rax , 0   					; error check
	jl  error      					; error if rax is less than 0
	ret

error:
	neg	rax                         ; errno codes are positive
	mov	r8, rax					; store value rax in r8
	push r8						; store value in stack
	call __errno_location        ; call the function __errno_location which returns the address or put the error
	pop r8
	mov [rax], r8 					; here rax contains the address of errno so by doing this we put rdi in errno
	mov rax, -1
	ret