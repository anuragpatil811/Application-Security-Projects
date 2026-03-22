#include <stdio.h>
#include <string.h>

void processTransaction(char* userInput) {
    char buffer[100]; // vulnerable buffer

    strcpy(buffer, userInput); // no bounds checking
    printf("Processing transaction: %s\n", buffer);
}

int main() {
    char userInput[1024];

    printf("Enter transaction details: ");
    fgets(userInput, 1024, stdin);

    processTransaction(userInput);

    return 0;
}