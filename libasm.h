#ifndef _LIBASM_H
    #define _LIBASM_H

    #include <errno.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>

    size_t		ft_strlen(char *str);
    char		*ft_strcpy(char *dest, const char *src);
    int		    ft_strcmp(const char *s1, const char *s2);
    ssize_t		ft_write(int fd, const void *buf, size_t count);
    // char		*ft_strdup(const char *s);
    // ssize_t		ft_read(int fd, void *buf, size_t count);

#endif