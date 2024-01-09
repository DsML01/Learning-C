#include <stdio.h>

int main()
{
    int lukelife, vaderlife;
    scanf("%d%d", &lukelife, &vaderlife);

    int ny = 3, nx = 3;
    int golpesluke[ny][nx], golpesvader[ny][nx];

    int somaluke = 0,somaluketransversal1 = 0,somaluketransversal2 = 0;
    int somavader = 0, somavadertransversal1 = 0, somavadertransversal2 = 0;

    int numrodadas = 10;
    for(int rodada = 1; rodada <= numrodadas; rodada++)
    {
        //scan luke
        int iy = 0, ix = 0;

        for(iy = 0; iy < ny; iy++)
        {
            for(ix = 0; ix < nx; ix++)
            {
                scanf("%d", &golpesluke[iy][ix]);
            }
        }

        //scan vader
        for(iy = 0; iy < ny; iy++)
        {
            for(ix = 0; ix < nx; ix++)
            {
                scanf("%d", &golpesvader[iy][ix]);
            }
        }

        //soma total luke
        iy = 0, ix = 0;
        
        for(iy = 0; iy < ny; iy++)
        {
            for(ix = 0; ix < nx; ix++)
            {
                somaluke += golpesluke[iy][ix];
            }
        }
        
        //soma transversal principal luke
        iy = 0, ix = 0;
        
        for(iy = 0; iy < ny; iy++)
        {
            somaluketransversal1 += golpesluke[iy][ix];
            ix += 1;
        }
        
        // soma transversal secundaria luke
        ix = nx-1;
        
        for(iy = 0; iy < ny; iy++)
        {
            somaluketransversal2 += golpesluke[iy][ix];
            ix -= 1;
        }

        //soma total vader
        for(iy = 0; iy < ny; iy++)
        {
            for(ix = 0; ix < nx; ix++)
            {
                somavader += golpesvader[iy][ix];
            }
        }
        //soma transversal principal vader
        ix = 0;
        for(iy = 0; iy < ny; iy++)
        {
            somavadertransversal1 += golpesvader[iy][ix];
            ix += 1;
        }

        //soma transversal secundaria vader
        ix = nx-1;
        
        for(iy = 0; iy < ny; iy++)
        {
            somavadertransversal2 += golpesvader[iy][ix];
            ix -= 1;
        }

        int idkvader, idkluke;

        if(somaluke == 3)
        {
            if(somaluketransversal1 == 3)idkluke = 1;
            else if(somaluketransversal2 == 3) idkluke = 2;
            else idkluke = 0;
        }
        else idkluke = 0;

        if(somavader == 3)
        {
            if(somavadertransversal1 == 3) idkvader = 1;
            else if(somavadertransversal2 == 3) idkvader = 2;
            else idkvader = 0;
        }
        else idkvader = 0;

        if(idkluke == 0 && idkluke == 0)
        {
            vaderlife -= 0;
            lukelife -= 0;
        }
        if(idkluke == 1 && idkvader == 0)
        {
            vaderlife -= 15;
        }
        if(idkluke == 2 && idkvader == 0)
        {
            vaderlife -= 15;
        }
        if(idkluke == 1 && idkvader == 1)
        {
            vaderlife -= 15;
            lukelife -= 15;
        }
        if(idkluke == 2 && idkvader == 2)
        {
            vaderlife -= 15;
            lukelife -= 15;
        }
        if(idkluke == 1 && idkvader == 2)
        {
            vaderlife -= 0;
            lukelife -= 0;
        }
        if(idkluke == 0 && idkvader == 1)
        {
            lukelife -= 15;
        }
        if(idkluke == 0 && idkvader == 2)
        {
            lukelife -= 15;
        }
        if(idkluke == 2 && idkvader == 1)
        {
            vaderlife -= 0;
            lukelife -= 0;
        }      

        if(lukelife == 0)
        {
            if(vaderlife==0)
            {
                printf("Houve empate.\n");
                rodada += 10;
            }
            else
            {
                printf("Darth Vader venceu.\n");
                rodada += 10;
            } 
        }
        else if(vaderlife == 0)
        {
            printf("Luke Skywalker venceu.\n");
            rodada += 10;
        }
        else if(rodada == 10)
        {
            if(lukelife > vaderlife) printf("Luke Skywalker venceu.\n");
            if(vaderlife > lukelife) printf("Darth Vader venceu.\n");
            if(lukelife == vaderlife) printf("Houve empate.\n");
        }
        
        somaluke = 0, somaluketransversal1 = 0, somaluketransversal2 = 0;
        somavader = 0, somavadertransversal1 = 0, somavadertransversal2 = 0;
        idkluke = 0, idkvader = 0;
    }
    return 0;
}