#include <stdio.h>

int conta(a, b, cont, n) {
    if (n == 50) printf ("%d", cont);
    
    else
    {
        if ((n % a) == 0 && (n % b) == 0)
        {
            return conta(a ,b , cont + 1, n + 1);
        }

        else 
        {
            return conta(a ,b ,cont ,n + 1);
        }
    }
}

int main () {

    int a, b;

    scanf ("%d%d", &a,&b);

    conta(a, b, 0, 1);

    return 0;
}