#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//https://leetcode.com/problems/valid-palindrome
int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("No command-line arguments provided.\n");
        return 1;
    }

    char* container = malloc(1 * sizeof(char));
    if (container == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    container[0] = '\0';

    for (int i = 1; i < argc; i++) {
        if (argv[i] != NULL) {
            int length = strlen(argv[i]);
            for (int j = 0; j < length; j++) {
                //printf("%p \n", (void*)&argv[i][j]);
                container = realloc(container, (strlen(container) + 2) * sizeof(char));
                if (container == NULL) {
                    printf("Memory reallocation failed.\n");
                    return 1;
                }
                snprintf(container + strlen(container), 2, "%c", argv[i][j]);
            }
        } else {
            printf("Invalid argument: %s\n", argv[i]);
        }
    }

    printf("Dynamic string: %s\n", container);
    //CLeanse the string
    for (int i = 0; i < strlen(container); i++) {
        //if number eleminate it
        if (container[i] >= '0' && container[i] <= '9'){
            container[i] = '\0';
            for (int j = i + 1; j < strlen(container); j++) {
                container[j - 1] = container[j];
            }
            container = realloc(container, strlen(container) + 1);
        }
        //if maj make it min
        if (container[i] >= 'A' && container[i] <= 'Z'){
            container[i] = container[i] + 32;
        }
    }
    printf("Processed dynamic string: %s\n", container);
    //determinate if it's palaindrom or not
    char* ptr1 = container;
    char* ptr2 = container + strlen(container) - 1;
    for (int i = 0; i < strlen(container); i++){
        if(*ptr1 != *ptr2){
            printf("\x1b[31mError: non palindrome\x1b[0m\n");
            free(container);
            return 1;
        }
        ptr1++;
        ptr2--;
    }
    printf("\x1b[32mPALAINDROME !\x1b[0m\n");
    free(container);
    return 0;
}
/*
gcc -o palindrome 155_palaindrome/main.c
*/
