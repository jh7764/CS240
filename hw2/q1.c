#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define max_len 100

int main(){
    char array[max_len];
    int frequencies[26] = {0};
    printf("Enter a string (up to a 100 characters): ");
    fgets(array, max_len, stdin);
    for (int i = 0; i < strlen(array); i++){
        if (isalpha(array[i])){
            char ch = tolower(array[i]);
            frequencies[ch-'a']++;
        }
    }
    for (int j = 0; j < 26; j++){
        if (frequencies[j] > 0){
        printf("%c: %d\n", toupper('a' + j), frequencies[j]);
        }
    }
    return 0;
}
