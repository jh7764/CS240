#include <stdio.h> 

/* Project: Hw q2
Name: Jenna Hayek
Date: 10/06/2024
File: q2.c
Notes: prints a hourglass-shaped star figure
*/

int main()
{
    int n;  
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (int i = n; i > 1; i--){
        for (int j = n-i; j >= 1; j--){
            printf(" ");
        }
        for (int k = 0; k < i; k++){
            printf("* ");
        }
        printf("\n");
    }
    for (int i=1; i<= n; i++)
    {
        for (int j = n-i; j >= 1; j--){
            printf(" ");
        }
        for (int k = 1; k <= i; k++){
            printf("* ");
        }
        printf("\n");
    }
   
    
    return 0;

}

