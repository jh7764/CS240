 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>


void rmdup(char* str){
    char arr[256] = {0};
    char* p1 = str;
    char* p2 = str;
    
    while (*p1 != '\0') {
            if (*p1 == ' ') {
               *p2 = *p1;
                p2++;
            }
            else if (arr[*p1] == 0){
                arr[*p1]++;
                *p2 = *p1;
                p2++;
            }
            p1++;
    }
    *p2 = '\0';
}

int main(){
    char arr1[100];
    char arr2[100];
    char* concatstr = NULL;
    
    
    printf("Enter the first string: ");
    fgets(arr1, sizeof(arr1), stdin);
    arr1[strcspn(arr1, "\n")] = '\0';
    
    printf("Enter the second string: ");
    fgets(arr2, sizeof(arr2), stdin);
    arr2[strcspn(arr2, "\n")] = '\0';
    
    int total_len = strlen(arr1) + strlen(arr2)+1;
    concatstr = (char* )malloc(total_len * sizeof(char));
    if (concatstr == NULL){
        return 1;
    }
    
    char* p = concatstr;
    char* str1 = arr1;
    char* str2 = arr2;
    while (*str1) {
        *p = *str1;
        str1++;
        p++;
    }
    while (*str2) {
        *p = *str2;
        str2++;
        p++;
    }
    *p = '\0';
  
    rmdup(concatstr);
    
    printf("Concatenated string without duplicates: %s\n", concatstr);
    
    free(concatstr);
    
    return 0;
}
