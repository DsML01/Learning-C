#include <stdio.h>

char analise(int a[], int n, int i, int s, int e, int tf, int c){

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

void leituras(int n, int no, int c) {

    int a[n];
    
    int s,e; 

    if (no == n) return;

    scanf("%d%d" &s,&e);

    analise (a[], n, 0, s, e, 1, c);

    leituras (n,no+1);

}

int main () {

    int n,c;

    scanf("%d%d", &n,&c);

    leituras(n, 0, c);

    return 0;
}