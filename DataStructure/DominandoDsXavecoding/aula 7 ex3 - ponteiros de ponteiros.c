#include <stdio.h>
#include <stdlib.h>

int main()
{
    double z = 2.5;
    double *fp;
    fp = &z;

    //INCRIVELMENTE, O z É PRINTADO EM TODOS OS CASOS
    printf("*&z = %lf\n", *&z);
    printf("*fp = %lf\n", *fp);
    printf("**&fp = %lf\n", **&fp);
}