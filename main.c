#include <stdio.h>
#include <string.h>
#include "libasm.h"


int main() {
// strlen
    printf("appel de ft_strlen\n");
    char *message = "d";
    size_t length = ft_strlen(message);
    printf("Length: %zu\n", length);

    printf("fin de la section strlen\n");

// strcpy
    printf("appel de ft_strcpy\n");
    char src[50] = "Hello, Assembly!";
    char dest[50];

    ft_strcpy(dest, src);

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    printf("fin de la section strcpy\n");

    printf("appel de ft_strcmp\n");
    char src1[50] = "";
    char dest1[50] = "";
    printf("ft_strcmp: %d\n", ft_strcmp(src1, dest1));
    printf("strcmp: %d\n", strcmp(src1, dest1));
    printf("fin de la section strcmp\n");


    return 0;
}