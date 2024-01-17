#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extractComments(char *code) {
    int i = 0;
    while (code[i] != '\0') {
        if (code[i] == '/' && code[i + 1] == '/') {
            // Single-line comment
            while (code[i] != '\n' && code[i] != '\0') {
                putchar(code[i]);
                i++;
            }
            putchar('\n');
        } else if (code[i] == '/' && code[i + 1] == '*') {
            // Multi-line comment
            i += 2;
            while (!(code[i] == '*' && code[i + 1] == '/')) {
                putchar(code[i]);
                i++;
            }
            i += 2;
        } else {
            i++;
        }
    }
}

int main() {
    FILE *file;
    char filename[100];
    char line[1000];
    char code[10000] = ""; // Maximum size of the input code, adjust as needed
    char delimiter[] = "###"; // Adjust the delimiter as needed

    printf("Enter the file name:\n");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the file content
    while (fgets(line, sizeof(line), file) != NULL) {
        strcat(code, line);
    }

    // Close the file
    fclose(file);

    printf("\nComments:\n");
    extractComments(code);
    printf("\n");

    return 0;
}
