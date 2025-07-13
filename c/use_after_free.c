#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
    size_t username_length = 10;
    char* username = malloc(username_length * sizeof(char));
    free(username);

    size_t input_length = 10;
    char* input = malloc(input_length * sizeof(char));
    printf("Input: ");
    if(!fgets(input, input_length, stdin)){
        printf("No input\n");
        return -1;
    };
    // fgets also includes \n in the string. strcspn will search for its location and return it so that it can be set to 0.
    // the location of \0 will be returned if \n couldn't be found.
    input[strcspn(input, "\n")] = 0;

    if(strncmp("admin", username, 6) == 0){
        printf("{admin}\n");
    }
    return 0;
}
