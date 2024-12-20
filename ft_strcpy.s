bits 64

global ft_strcpy

ft_strcpy:
    mov rcx, 0                      ; initialise rax a 0
    ; jmp loop                        ; lance la section loop

    loop:
        mov al, BYTE [rsi + rcx]    ; copie le caractere de la variable source dans al
        mov BYTE [rdi + rcx], al    ; copie al dans la chaine dest
        cmp al, 0                   ; check si al = 0
        je  done                    ; jump a done si al = 0
        inc rcx                     ; incremente rax
        jmp loop                    ; recommence loop

    done:
        mov rax, rdi
        ret
        
        