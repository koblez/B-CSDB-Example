#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void secret(void){
    printf("{93aa220a-775b-4511-85b9-f0f669961da1}\n");
}

int main(int argc, char const *argv[]){
    char input[10];
    printf("%p\n", secret);
    printf("Enter password: ");
    if(!fgets(input, 10, stdin)){
        printf("No input\n");
        return -1;
    }
    return 0;
}
