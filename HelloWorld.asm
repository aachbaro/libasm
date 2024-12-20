bits 64

section .data
    message db 'Hello World !', 10

section .text
    global _start
    _start:
    ; section write
        mov rax, 1 ; indique quelle fonction j'utilise, en l'occurence write, indique par le code 1
        mov rdi, 1 ; rdi indique le premier argument que je donne a la fonction indiquee dans rax, en l'occurence le fd pour write
        mov rsi, message ; rsi indique la chaine de caractere (second arg)
        mov rdx, 13+1 ; etc..
        syscall

    ; section exit
        mov rax, 60
        mov rdi, 0
        syscall


; mov = deplacement de donnees