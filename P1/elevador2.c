#include <stdio.h>

char analise(int n, int i, int s, int e, int tf, int c){
    //LITERALMENTE NÃO PRECISA DE ARRAY
    if (i == n) 
    {
        if (tf == 1) printf ("S\n");
        else printf ("N\n");
        
    }
    else 
    {
        if (a[i] == a[0]) 
        {
            a[i] = e;

            if (a[i] < c) tf = 0;

            else tf = 1;
        }
        
        else 
        {
            a[i] = a[i-1] - s + e;

            if (a[i] < c) tf = 0;

            else tf = 1;

        }
    }

}

void leituras(int a [], int n, int i, int c) {

    int s,e; 

    if (i == n) 
    {
        if (tf == 1) printf ("S\n");
        else printf ("N\n");  
    }
    else 
    {
        scanf("%d%d" &s,&e);

        if (a[0]) 
    }
}

int main () {

    int n,c;

    scanf("%d%d", &n,&c);

    int a[n];

    a[0] = 0;

    leituras(a[], n, 0, c);

    return 0;
}