#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n/2+1; i++){
        for(int j = 0; j < n/2+1 - i - 1; j++){
            printf("-");
        }
        for(int j = 0; j < ; j++){
            printf("*");
        }
        for(int j = 0; j < ; j++){
            printf("-");
        }
        printf("\n");
    }



    return 0;
}