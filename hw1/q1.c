#include <stdio.h>
/* Project: Hw q1
Name: Jenna Hayek
Date: 10/06/2024
File: q1.c
Notes: prints a right-side star triangle
*/

int main(){
    int n;  
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 2*(n-i); j++){
            printf(" ");
        }
        for (int k = 1; k <= i; k++){
            printf(" *");
        }
        printf("\n");
    }
    return 0;
}
