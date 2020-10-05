#include <stdio.h>
void swapStrings(char **destination, char **source);           

int main(){
    char *str1 = "Hello";
    char *str2 = "BigWorld";
    // define and initialize str1
    // define and initialize str2

    printf("str1: %s, str2: %s\n",str1,str2);
    swapStrings(&str1, &str2);
    printf("str1: %s, str2: %s\n",str1,str2);

    return 0;
}

void swapStrings(char **destination, char **source){
    char *temp = *destination;
    *destination = *source;
    *source = temp;
}
    // swaps contents of two strings
    // implement this function without using any built in functions
