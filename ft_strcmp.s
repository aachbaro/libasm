global ft_strcmp

ft_strcmp:
    mov rcx, 0                      ; initialise rax a 0

    loop:
        ;verifier si il y a un fin de string
        cmp BYTE [rsi + rcx], 0
        je done
        cmp BYTE [rdi + rcx], 0
        je done

        ;comparer les caracteres a l'index rcx
        mov al, BYTE [rdi + rcx]
        cmp BYTE [rsi + rcx], al
        jne done    ;sortir si non egal

        ;incrementer et looper
        inc rcx
        jmp loop

    done:
        movzx rax, byte [rdi + rcx]   
        movzx rbx, byte [rsi + rcx]   
        sub rax, rbx               
        ret            
        
        