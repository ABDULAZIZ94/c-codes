#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

// Function to check if a character is a C special character
int is_special_char(char c) {
    // List of C special characters
    const char *special_chars = "!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`";
    return strchr(special_chars, c) != NULL;
}

// Function to trim special characters from a string
void trim_special_chars(char *str) {
    int src_idx = 0, dst_idx = 0;
    char c;

    while ((c = str[src_idx++]) != '\0') {
        if (!is_special_char(c)) {
            str[dst_idx++] = c;
        }
    }
    str[dst_idx] = '\0';
}

int main() {
    char input[MAX_LEN];

    // Read input from the user
    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Trim special characters
    trim_special_chars(input);

    // Print the result
    printf("String after trimming special characters: %s\n", input);

    return 0;
}
