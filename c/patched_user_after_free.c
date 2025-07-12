#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* chars;
    uint32_t length;
} String;

uint32_t my_strcspn(String input, String rejected){
    for (uint32_t i = 0; i < input.length; i++){
        for (uint32_t k = 0; k < rejected.length; k++){
            // This could be improved further with a "Get" function that checks that the access isn't out of bounds
            if (input.chars[i] == rejected.chars[k]){
                return i;
            }
        }
    }
    return input.length;
}

uint32_t my_strcmp(String s1, String s2){
    if (s1.length != s2.length){
        return 1;
    }
    for (uint32_t i = 0; i < s1.length; i++){
        if (s1.chars[i] != s2.chars[i]){
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[]){
    String username = {
        .chars = NULL,
        .length = 10
    };
    username.chars = malloc(username.length * sizeof(char));
    if (username.chars == NULL){
        printf("Malloc for username string failed!\n");
        return -1;
    }
    free(username.chars);
    username.chars = NULL;
    username.length = 0;

    String input = {
        .chars = NULL,
        .length = 10
    };
    input.chars = malloc(input.length * sizeof(char));
    if (input.chars == NULL){
        printf("Malloc for input string failed!\n");
        return -1;
    }
    printf("Input: ");
    if(!fgets(input.chars, input.length, stdin)){
        printf("No input\n");
        return -1;
    }
    String rejected = {
        .chars = "0",
        .length = 1
    };
    // This will shorten the known length, a further improvement would be to use a length field for the current length
    // and a capacity field for the max. allowed length that remains unchanged.
    input.length = my_strcspn(input, rejected);

    if (username.chars != NULL){
        if(my_strcmp((String) {"admin", 6}, username) == 0){
            printf("{admin}\n");
        }
    }
    return 0;
}
