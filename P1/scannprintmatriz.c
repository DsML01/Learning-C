#include <stdio.h>

int main()
{
    int matriz[5][5];
                        
    for(int m = 0; m < 5; ++m){
        for(int n = 0; n < 5; ++n){
            scanf("%d", &matriz[m][n]);
        }
    }
                        
    for(int m = 0; m < 5; ++m){
        for(int n = 0; n < 5; ++n){
            printf("%d ", matriz[m][n]);
        }
        printf("\n");
    }

    return 0;
}
