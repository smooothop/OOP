#include <stdio.h>

int main(){

    int a;

    scanf("%d", &a);

    for(int i = 0; i < a/2+1; i++){

        for(int j = (a/2+1)-i-1; 0 < j; j--){
            printf("-");
        }
        for(int j = 0; j < (i+1)*2-1; j++){
            printf("*");
        }
        for(int j = (a/2+1)-i-1; 0 < j; j--){
            printf("-");
        }
        printf("\n");
    }
    


    return 0;
}