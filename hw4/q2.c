#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    int n;
    int choice;
    
    printf("Please input the number of values in your array: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Input your array values, you should input %d values: \n", n);
    for (int i = 0; i < n; i++){
        printf("element - %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("\n");
    printf("Choose sorting order: \n 1. Ascending\n 2. Descending\n");
    scanf("%d", &choice);
    
    if (choice != 1 && choice != 2){
        printf("Invalid option\n");
        return 1;
    }
    
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (choice == 1){
                if (arr[j] > arr[j+1]){
                    swap(&arr[j+1], &arr[j]);
                }
            }
            if (choice == 2){
                if (arr[j] < arr[j+1]){
                    swap(&arr[j], &arr[j+1]);
                }
            }
        }
    } 
        
        
    
    printf("\nThe elements in the array after sorting: \n");
    for (int i = 0; i < n; i++){
        printf("element - %d: %d\n", i+1, arr[i]);
    }
    
    
    free(arr);

    return 0;
}
