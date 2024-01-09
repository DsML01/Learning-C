#include <stdio.h>

void ler (int p[], int n, int i)
{
    if (i == n) return;

    scanf("%d", p[i]);
    ler (p[], n, i + 1);

}

int bubble (int p[],int n,int i)
{

    if (i == n) return 0;

    bubble2 (p[] ,4 , 0);

    return bubble (p[] ,n ,i + 1);
}

int bubble2 (int p[] ,int n ,int i) 
{
    if (i == n) return 0;

    if ( p[i] > p[i + 1] ) 
    {

        if (p[i] > p[i + 1])

    }
}

int main () {

    int p[4];

    ler(p[], 4, 0);

    bubble (p[],4,0);
    
    return 0;
}