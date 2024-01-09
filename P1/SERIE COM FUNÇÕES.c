#include <stdio.h>
int eh_primo(primo,x) {
    if (primo==x){
        return 1;
    }
    if (primo % x == 0|| primo<=1) {
        return 0;
    }
    return eh_primo (primo, x+1);
}

int proximo_primo(primo) {
    if (eh_primo(primo,2)==1) {
        return primo;
    } 
    else {
       return proximo_primo(primo+1);
    }
}

int fatores (int n,int no,int primo,double soma) {
    double f= fat(n);
    if (n>no) {
        printf("\n");
        printf ("%.2lf", soma);
    }
    else if(n==1) {
        printf ("1!/1");
        return fatores(n+1,no,primo,soma+1);
    }
    else {
        if (n<=primo) {
            printf (" + %d!/%d", n,primo);
            soma=soma+(f/primo);
            return fatores(n+1,no,primo,soma);
        }
        else {
            primo=proximo_primo(primo+1,soma);
            return fatores(n,no,primo,soma);
        }
        
    }
}

int fat(int n){
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n*fat(n - 1);
    }
}

int main () {
    int n,primo;
    scanf ("%d", &n);   
    fatores(1,n,2,0);
}   