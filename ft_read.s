global ft_read
extern __errno_location

section .text
ft_read:
	mov rax, 0				; syscall read
	syscall
	cmp rax, 0				; check the return of the syscall
	jl error				; go to error if rax != 0
	ret						; return rax if everything went well
error:
	neg		rax			; turn rax to positive number
	mov		rdi, rax		; put rax in rdi
	call		__errno_location	wrt ..plt; get a pointer on errno
	mov		[rax], rdi		; put the returned error in errno
	mov		rax, -1			; set the return value to -1
	ret					; return rax
