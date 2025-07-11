#include <stdio.h>

void secret(void){
    printf("{93aa220a-775b-4511-85b9-f0f669961da1}\n");
}

int main(int argc, char const *argv[]){
    char input[10];
    printf("%p\n", secret);
    printf("Enter password:");
    scanf("%s", input);
    return 0;
}
