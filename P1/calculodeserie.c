#include <stdio.h>
#include <math.h>

double analisea(double a[], int n, int i, double d, int pa, double D)
{

    if (i == n) return 0;

    else
    {
        a[i] = d/D;

        pa += 2;

        return analisea(a, n, i + 1, d + 2, pa, pow(2, pa));

    }


}

double analiseb (double b[], int n, int i, int pb, double d, int mD, double D)
{
    if (i == n) return 0;

    else
    {
        b[i] = d/D;
        
        pb += 2;
        
        mD += 1;

        return analiseb(b, n, i + 1, pb, pow(2,pb), mD, 3 * mD);
    }

}


double analisec(double a[], double b[], double c[], int n, int i)
{
    if(i == n) return 0;

    else if(i == n - 1)
    { 
        c[i] = a[i];
        
        printf("%.2lf\n", c[i]);
        return analisec(a, b, c, n, i + 1);
    }
    else
    {
        if((i + 1) % 2 == 0) 
        {
            c[i] = b[i];
            c[i + 1] = a[i];
        }

        else
        {
            c[i] = a[i];
            c[i + 1] = a[i];
        }
        printf("%.2lf\n%.2lf\n", c[i], c[i + 1]);
        
        return analisec(a, b, c, n, i + 2);
    }

}

/*int soma(int c[], int n, int i)
{

}*/

int main ()
{
    int n;

    scanf("%d", &n);

    double a[n], b[n], c[n];

    int pa = 0, pb = 1, mD = 1;

    analisea(a, n, 0, 1, pa, pow(2, pa));

    analiseb(b, n, 0, pb, pow(2,pb), mD, 3 * mD);

    analisec(a, b, c, n, 0);

    //soma(c, n, 0);

    return 0;
}