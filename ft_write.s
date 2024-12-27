extern __errno_location

global ft_write

ft_write:
    mov rax, 1          ; Numéro du syscall pour write
    mov rdi, rdi        ; 1er argument : fd
    mov rsi, rsi        ; 2e argument : buffer
    mov rdx, rdx        ; 3e argument : size
    syscall             ; Appel système

    cmp rax, 0          ; Vérifier si la valeur de retour est négative
    jl error            ; Si oui, aller à la gestion des erreurs
    ret                 ; Sinon, retourner normalement

error:
    mov rdi, rax        ; Conserver la valeur de retour (-1)
    neg rdi             ; Transformer en un code d'erreur positif
    call __errno_location ; Appeler errno_location pour obtenir l'adresse d'errno
    mov [rax], edi      ; Mettre à jour errno avec le code d'erreur
    mov rax, -1         ; Retourner -1 comme write le ferait
    ret