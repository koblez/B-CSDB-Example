#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){

    char* username = malloc(10*sizeof(char));
    free(username);

    char* user_input = malloc(10*sizeof(char));
    if(!fgets(user_input, 10, stdin)){
        printf("No input\n");
        return -1;
    };
    // fgets also includes \n in the string. strcspn will search for its location and return it so that it can be set to 0.
    // the location of \0 will be returned if \n couldn't be found.
    user_input[strcspn(user_input, "\n")] = 0;

    if(strncmp("admin", username, 6) == 0){
        printf("{admin}\n");
    }

    return 0;
}
