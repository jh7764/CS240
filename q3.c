#include <stdio.h>
#include <math.h>

/* Project: Hw q3
Name: Jenna Hayek
Date: 10/06/2024
File: q3.c
Notes: prints a the sum of the series x-x^3+x^5-x^7...
*/

int main(){
    int sum, sign, x, nt, ct;

    printf("Input the value for x: ");
    scanf("%d", &x);
    printf("Input the number of terms: ");
    scanf("%d", &nt);


    sum = x;
    sign = -1;

    printf("The values of the series: \n");
    printf("%d\n", x);

    for (int i = 1; i < nt; i++){
        int exp = 2*i+1;
        ct = pow(x,exp);
        if (i % 2 == 1){
            ct = sign*ct;

        } 
        printf("%d\n", ct); 
        
        sum += ct;
        

    }
    printf("\nThe sum = %d\n", sum);
    return 0;
}