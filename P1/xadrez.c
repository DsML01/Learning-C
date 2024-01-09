#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ny = n, nx = n;
    int mapa[ny][nx];

    for(int iy = 0; iy<ny; iy++)
    {
        for(int ix = 0; ix<nx; ix++)
        {
            scanf("%d", &mapa[iy][ix]);
        }
    }
    int z, k, x, y;
    scanf("%d%d%d%d", &z, &k, &x, &y);
    int aziul = 0, nosredna = 0;

    int iz = z, ik = k, ix = x, iy = y;

    for(int i = 0; i<1; i++)
    {
        while(mapa[iz][k] == 0)
        {
            if(mapa[iz-1][k] == mapa[x][y]) break;
            else if((iz-1) < 0) break;
            else if(mapa[iz-1][k] == 1)
            {
                aziul ++;
                mapa[iz-1][k] = 0;
                break;
            }
            else if (mapa[iz-1][k] == 0) iz--;
        }
        iz = z;
        while(mapa[iz][k] == 0)
        {
            if(mapa[iz+1][k] == mapa[x][y]) break;
            else if((iz+1) >= ny ) break;
            else if(mapa[iz+1][k] == 1)
            {
                aziul ++;
                mapa[iz+1][k] = 0;
                break;
            }
            else if (mapa[iz+1][k] == 0) iz++;
        }
        iz = z;
        while(mapa[z][ik] == 0)
        {
            if(mapa[z][ik-1] == mapa[x][y]) break;
            else if((ik-1) < 0) break;
            else if(mapa[z][ik-1] == 1)
            {
                aziul ++;
                mapa[z][ik-1] = 0;
                break;
            }
            else if (mapa[z][ik-1] == 0) ik--;
        }
        ik = k;
        while(mapa[iz][k] == 0)
        {
            if(mapa[iz+1][k] == mapa[x][y]) break;
            else if((ik+1) >= nx) break;
            else if(mapa[z][ik+1] == 1)
            {
                aziul ++;
                mapa[z][ik+1] = 0;
                break;
            }
            else if (mapa[z][ik+1] == 0) ik++;
        }
        ik = k;
        //now i'm gonna do nosredna
        // x ^ y.
        while(mapa[ix-1][iy-1] == 0)
        {
            if(mapa[ix-1][iy-1] == mapa[z][k]) break;
            else if((ix-1) < 0 || (iy-1) < 0) break;
            else if(mapa[ix-1][iy-1] == 1)
            {
                nosredna ++;
                mapa[ix-1][iy-1] = 0;
                break;
            }
            else if (mapa[ix-1][iy-1] == 0) 
            {
                ix--;
                iy--;
            }
        }
        ix = x;
        iy = y;
        while(mapa[ix-1][iy+1] == 0)
        {
            if(mapa[ix-1][iy+1] == mapa[z][k]) break;
            else if((ix-1) < 0 || (iy+1) >= nx) break;
            else if(mapa[ix-1][iy+1] == 1)
            {
                nosredna ++;
                mapa[ix-1][iy+1] = 0;
                break;
            }
            else if (mapa[ix-1][iy+1] == 0) 
            {
                ix--;
                iy++;
            }
        }
        ix = x;
        iy = y;
        while(mapa[ix+1][iy+1] == 0)
        {
            if(mapa[ix+1][iy+1] == mapa[z][k]) break;
            else if((ix+1) >= ny || (iy+1) >= nx) break;
            else if(mapa[ix+1][iy+1] == 1)
            {
                nosredna ++;
                mapa[ix+1][iy+1] = 0;
                break;
            }
            else if (mapa[ix+1][iy+1] == 0) 
            {
                ix++;
                iy++;
            }
        }
        ix = x;
        iy = y;
        while(mapa[ix+1][iy-1] == 0)
        {
            if(mapa[ix+1][iy-1] == mapa[z][k]) break;
            else if((ix+1) >= ny || (iy-1) < 0) break;
            else if(mapa[ix+1][iy-1] == 1)
            {
                nosredna ++;
                mapa[ix+1][iy-1] = 0;
                break;
            }
            else if (mapa[ix+1][iy-1] == 0) 
            {
                ix++;
                iy--;
            }
        }
        ix = x;
        iy = y;
    }
    printf("aziul matou %d\n", aziul);
    printf("nosredna matou %d\n", nosredna);

    return 0;
}