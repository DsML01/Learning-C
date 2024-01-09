#include<stdio.h>

int main()
{
    int numapostas;
    scanf("%d", &numapostas);
    
    int ny = numapostas, nx = 20;
    char matriz[ny][nx];

    for(int iy = 0; iy<ny; iy++)
    {
        for(int ix = 0; ix<nx; ix++)
        {
            matriz[iy][ix] = -1;
        }
    }
    int n = (ny*nx);
    char array[n];
    int newn;
    for(newn = 0; i<n; i++)
    {
        scanf("%c", &array[newn]);
    }

    for(int iy = 0; iy<ny; iy++)
    {
        int i = 0;
        for(int ix = 0; ix<nx; ix++)
        {
            if(array[i + 1] == ',') matriz[iy][ix] = array[i];
            else
            i++;
        }
    }

    return 0;
}