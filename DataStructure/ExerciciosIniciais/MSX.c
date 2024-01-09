        #include <stdio.h>
        #include <stdlib.h>
        #include <ctype.h>

        void alocar(char **matriz, int iy, int nx)
        {
            //if(iy == nx) return;

            char *str = (char) calloc(nx,sizeof(char));

            return;
        }

        int size(char *matriz, int retorno, int ny)
        {

            int iy = 0;
            while((matriz + iy) != NULL)
            {
                iy++;
                retorno++;
            }

            return retorno;
        }

        int main()
        {
            int ny = 50, nx = 75;
            char **matriz = (char**) calloc(ny,sizeof(char*));
            int iy = 0, ix = 0;

            while(scanf("%c", matriz[iy][ix]) != EOF)
            {
                //if(matriz[iy][ix] != '\n') matriz[iy][ix] = matriz[iy][ix] + '32';

                //printf("%c", matriz[iy][ix]);

                ix++;
                if(ix >= nx)
                {
                    ix = 0;
                    iy++;
                    alocar(matriz,iy,nx);
                }
                
            }

            for(iy = 0; iy < ny; iy++)
            {
                for(ix = 0; ix < nx; ix++)
                {
                    printf("%c", matriz[iy][ix]);
                }
            }

            /*int size = size(*matriz,0,ny) - 1;
            int bool;

            for(iy = 0; iy < size; iy++)
            {
                for(ix = 0; ix < nx; ix++)
                {
                    if(isalpha(matriz[iy][ix]) bool = 1;
                    else bool = 0;
                    
                    if(bool == 1) toupper(matriz[iy][ix]);
                }
            }*/
            
            return 0;
        }