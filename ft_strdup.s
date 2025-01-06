global ft_strdup
extern ft_strlen
extern malloc
extern ft_strcpy
extern __errno_location

section .text
ft_strdup:
	call ft_strlen			; put the length of the string in rax
	inc rax					; let the space for the \0
	push rdi				; push the string in the stack
	mov rdi, rax			; prepare the args for malloc syscall
	call malloc				; 
	cmp rax, 0				; check the ret of malloc
	je error				; jump to error if something went wrong
	mov rdi, rax			; set up the arg for ft_strcpy with the adress given by malloc
	pop rsi					; set up the second argument for ft_strcpy
	call ft_strcpy			; call to strcy
	ret						; return rax (ptr)

error:
	neg		rax			; turn rax to positive number
	mov		rdi, rax		; put rax in rdi
	call		__errno_location	; get a pointer on errno
	mov		[rax], rdi		; put the returned error in errno
	mov		rax, -1			; set the return value to -1
	ret					; return rax

