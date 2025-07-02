#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define size 10

int main(){
    int array[size];
    int rotate[size];
    printf("Enter 10 integers: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);  
    } 
    printf("Original array: ");
    for (int i = 0; i < size; i++){
       printf("%d ", array[i]);
    }
    rotate[0] = array[size-2];
    rotate[1] = array[size-1];
    for (int j = 0; j < size-2; j++){
        rotate[j+2] = array[j];
    }
    printf("\nRotated array: ");
    for (int j = 0; j < size; j++){
        printf("%d ", rotate[j]);
    }
    printf("\n");
    return 0;
}