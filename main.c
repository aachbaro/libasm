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
    char src1[50] = "bonjour";
    char dest1[50] = "";
    printf("ft_strcmp: %d\n", ft_strcmp(src1, dest1));
    printf("strcmp: %d\n", strcmp(src1, dest1));
    printf("fin de la section strcmp\n");

    printf("appel de ft_write\n");

    int fd;

    // Test 1: Write to stdout
    ft_write(1, "Hello, stdout!\n", 15);

    // Test 2: Write to a file
    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    ft_write(fd, "Hello, file!\n", 13);
    close(fd);

    // Test 3: Invalid file descriptor
    ssize_t ret = ft_write(-1, "Invalid fd\n", 11);
    if (ret == -1) {
        perror("ft_write");
    }

    printf("fin de la section ft_write\n");



    return 0;
}