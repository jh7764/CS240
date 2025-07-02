#include <stdio.h>
#include <stdlib.h>

int* reverseArray(int* arr, int n){
    int* reverse = (int* )malloc(n * sizeof(int));
    if (reverse == NULL) {
        return 1;
    }
    int* end = arr + n -1;
    for (int i = 0; i < n; i++){
        *(reverse + i) = *end--;
       
    }
   
    return reverse;
}

int* shiftby2(int* arr, int n){
    int* rotate = (int* )malloc(n * sizeof(int));
    if (rotate == NULL) {
        return 1;
    }
    int* start = rotate;
    int* first = arr;
    int* sec = arr + 1;
    for (int i = 2; i < n; i++){
        *(start++) = *(arr + i);
        
    }
    *(rotate + n - 1) = *(sec);
    *(rotate + n - 2) = *(first);
    
    return rotate;
}

int* shiftbyd(int* arr, int n, int m){
  int* rotate = (int* )malloc(n * sizeof(int));
    if (rotate == NULL) {
        return 1;
    }
    if (m == 0){
        return rotate;
    }
    m %= n;
    int* temp = rotate;
    int* end = rotate + n-m;
    for (int j = m; j < n; j++){
        *(temp++) = *(arr + j);
    }
    for (int i = 0; i < m; i++){
        *(end++) = *(arr+i);
    }
    
    return rotate;
    
}
    

int main(){
    int* array = NULL;
    int n;
    int m;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    

    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++){
        scanf("%d", *(array+i));
    }

    printf("Enter number of positions to rotate: ");
    scanf("%d", &m);
    
    int* rotatearrd = shiftbyd(array, n, m);
    int* revarr = reverseArray(rotatearrd, n);

    printf("Original Array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", *(array+i));
    }
    

    printf("\n");
    printf("Array after right rotation by %d positions: ", m);
    for (int i = 0; i < n; i++){
        printf("%d ", *(rotatearrd+i));
    }
    
    printf("\n");
    printf("Reversed Array after rotations: ");
    for (int i = 0; i < n; i++){
        printf("%d ", *(revarr+i));
    }
    printf("\n");

    free(array);
    free(revarr);
    free(rotatearrd);
    return 0;
}