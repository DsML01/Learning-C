#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void total(double valor, int veiculo){
    int n;
    scanf("%d", &n);
    if(n == 999){

        printf("%.2lf\n%d", valor, veiculo);

    }
    
    if(n>2){
        veiculo++;
        valor += (n-2)*12.89;
        return total(valor, veiculo);
    }
    return total(valor, veiculo);
}

int main(){
    total(0, 0);
    
    return 0;
}