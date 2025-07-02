#include <stdio.h>
#include <string.h>

#define max_len 100

int main(){
    char array[max_len];
    char reverse[max_len];
    printf("Enter a string (up to a 100 characters): ");
    fgets(array, max_len, stdin);
    if (array[(strlen(array))-1] == '\n'){
        array[(strlen(array))-1] = '\0';
    }
    

    printf("\nOriginal String: %s ", array);
    printf("\n");

    //reverse string
    for (int i = 0; i < (strlen(array)); i++){
    //array copying but take last element to be first element new array
        reverse[i] = array[(strlen(array))-1-i];
    }
    
    //print reverse string
    printf("Reversed String: %s ", reverse);
    printf("\n");
    return 0;

}
