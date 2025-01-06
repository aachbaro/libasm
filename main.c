#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "libasm.h"

int main() {
    // ft_strlen
    printf("ft_strlen:\n");
    char *message = "Hello, World!";
    size_t length = ft_strlen(message);
    printf("Length: %zu\n", length);

    // ft_strcpy
    printf("\nft_strcpy:\n");
    char src[50] = "Hello, Assembly!";
    char dest[50];
    ft_strcpy(dest, src);
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    // ft_strcmp
    printf("\nft_strcmp:\n");
    char src1[50] = "bonjour";
    char dest1[50] = "bonsoir";
    printf("ft_strcmp: %d\n", ft_strcmp(src1, dest1));
    printf("strcmp: %d\n", strcmp(src1, dest1));

    // ft_write
    printf("\nft_write:\n");
    int fd;

    // Test 1: Write to stdout
    ft_write(1, "Hello, stdout!\n", 15);

    // Test 2: Write to a file
    fd = open("test_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

    // ft_read
    printf("\nft_read:\n");
    char buffer[100];
    ssize_t bytes_read;

    // Test 1: Read from stdin
    printf("\nEnter text (press Enter): \n");
    bytes_read = ft_read(0, buffer, 100); // Reading from stdin
    if (bytes_read >= 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Read from stdin: %s\n", buffer);
    } else {
        perror("ft_read");
    }


    // Test 2: Read from a file
    fd = open("test_write.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    bytes_read = ft_read(fd, buffer, 100);
    if (bytes_read >= 0) {
        buffer[bytes_read] = '\0';
        printf("Read from file: %s\n", buffer);
    } else {
        perror("ft_read");
    }
    close(fd);

    // Test 3: Invalid file descriptor
    bytes_read = ft_read(-1, buffer, 100);
    if (bytes_read == -1) {
        perror("ft_read");
    }

    // ft_strdup
    printf("\nft_strdup:\n");

    // Test 1: Duplicate a string
    char *original = "This is a test string.";
    char *duplicate = ft_strdup(original);
    if (duplicate) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate); // Free the duplicated string
    } else {
        perror("ft_strdup");
    }

    // Test 2: Duplicate an empty string
    original = "";
    duplicate = ft_strdup(original);
    if (duplicate) {
        printf("Original: '%s'\n", original);
        printf("Duplicate: '%s'\n", duplicate);
        free(duplicate); // Free the duplicated string
    } else {
        perror("ft_strdup");
    }

    // Test 3: Duplicate a long string
    original = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    duplicate = ft_strdup(original);
    if (duplicate) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate); // Free the duplicated string
    } else {
        perror("ft_strdup");
    }

    return 0;
}