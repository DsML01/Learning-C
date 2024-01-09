#include<stdio.h>
#include<stdlib.h>

int **create_int_matrix(int ny, int nx)
{
    int **m = (int**) calloc(ny, sizeof(int*));

    for(int iy = 0; iy < ny; iy++)
    {
        m[iy] = (int*) calloc(nx, sizeof(int));
    }

    return m;
}

//o const significa que eh read only
void print_int_matrix(const int **m, int ny, int nx)
{
    printf("&m = %p, m = %p\n\n", &m, m);

    for(int iy = 0; iy < ny; iy++)
    {
        for(int ix = 0; ix < nx; ix++)
        {
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", iy, ix, &m[iy][ix], iy, ix, m[iy][ix]);
        }
        puts("");
    }
    return;
}

void add_scalar_into_int_matrix(int **m, int ny, int nx, int scalar)
{
    for(int iy = 0; iy < ny; iy++)
    {
        for(int ix = 0; ix < nx; ix++)
        {
            m[iy][ix] += scalar;
        }
    }
    return;
}

void destroy_int_matrix(int ***matrix, int ny, int nx)
{
    int **aux = *matrix;

    for(int ix = 0; ix < nx; ix++)
    {
        free(aux[ix]);
    }
    free(aux);
    *matrix = NULL;
}

int main()
{
    int ny = 3, nx = 3, scalar = 10;   
    //alocando a matriz
    int **m = create_int_matrix(ny,nx);

    //atribuindo valores a matriz
    int count = 1;
    for(int iy = 0; iy < ny; iy++)
    {
        for(int ix = 0; ix < nx; ix++)
        {
            m[iy][ix] = count++;
        }
    }

    print_int_matrix((const int**) m, ny, nx);

    add_scalar_into_int_matrix(m, ny, nx, scalar);

    print_int_matrix((const int**) m, ny, nx);

    destroy_int_matrix(&m, ny, nx);

    //m == NULL eh uma pergunta usando logica booleana
    //retorna 1 para verdadeiro e 0 para falso
    printf("m is NULL? %d\n", m == NULL);

    return 0;
}