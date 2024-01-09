#include <stdio.h>

int bubble2 (double p[] ,int n ,int i) 
{
    double a;

    if (i == n) return 0;

    if ( p[i] > p[i + 1] ) 
    {
        a = p[i];
        p[i]=p[i+1];
        p[i+1]=a;
    }
    else return bubble2(p ,n ,i + 1);
}


int bubble (double p[],int n,int i)
{

    if (i == n)
    {
        
        printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n", p[0], p[2], p[3], p[1]);
        
        return 0;
    }

    bubble2 (p ,4 , 0);

    return bubble (p ,n ,i + 1);
}

void ler (double p[], int n, int i)
{
    if (i == n)
    {
        bubble(p,n,i);
    }

    scanf("%lf", &p[i]);
    return ler (p, n, i + 1);

}

int main () {

    double p[4];

    ler(p, 4, 0);
    
    return 0;
}