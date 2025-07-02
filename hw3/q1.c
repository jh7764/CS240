#include <stdio.h>
#include <stdlib.h>

int* reverseArray(int* arr, int n){
    int* reverse = (int* )malloc(n * sizeof(int));
    if (reverse == NULL) {
        return 1;
    }
    int* end = arr + n-1;
    for (int i = 0; i < n; i++){
        *(reverse + i) = *end--;  
    }
   
    return reverse;
}

int* shift(int* arr, int n){
    int* rotate = (int* )malloc(n * sizeof(int));
    if (rotate == NULL) {
        return 1;
    }
    int* last = arr + n - 1;
    for (int i = 0; i < n; i++){
        *(rotate + i + 1) = *(arr + i);
    }
    *(rotate) = *(last);
    return rotate;
}

int main(){
    int* array = NULL;
    int n;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    array = (int* )malloc(n * sizeof(int));
    if (array == NULL) {
        return 1;
    }

    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++){
        scanf("%d", array+i);
    }
    
    int* reversedarr = reverseArray(array, n);
    int* rotatedarr = shift(reversedarr, n);

    printf("Original Array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", *(array+i));
    }
    
    printf("\n");
    printf("Reversed Array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", *(reversedarr+i));
    }
    
    printf("\n");
    printf("Shifted and Reversed Array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", *(rotatedarr+i));
    }
    printf("\n");
 
    free(array);
    free(reversedarr);
    free(rotatedarr);
    return 0;
}
