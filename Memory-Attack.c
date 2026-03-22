#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Input: %s\n", buffer);
}
int main() {
    char input[50];
    memset(input, 'A', sizeof(input));
    input[sizeof(input)-1] = '\0';
    vulnerable_function(input);
    return 0;
}