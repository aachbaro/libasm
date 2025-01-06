global ft_write
extern __errno_location

ft_write:
    test rsi, rsi               ; test !rsi
    jz invalid_argument         ; if !rsi, go to invalid_argument
	mov		rax, 1				; syscall write
	syscall
	cmp		rax, 0				; check write return value
	jl		error				; jump to error if rax != 0
	ret							; return rax

invalid_argument:
    ; Gérer le cas où un argument est invalide
    mov rax, -22                ; -EINVAL (22 = invalid argument)
    jmp error

error:
	neg		rax						; turn rax to positive number
	mov		rdi, rax				; put rax in rdi
	call		__errno_location	; get a pointer on errno
	mov		[rax], rdi				; put the returned error in errno
	mov		rax, -1					; set the return value to -1
	ret								; return rax
