#include <stdio.h>
#include <string.h>
void unsafe_function(char *) {
    char buffer[10];
    strcpy(buffer, input);
}

int main(int argc, char *argv[]) {
    unsafe_function(argv[1]);
    return 0;
}