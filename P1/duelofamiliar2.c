#include <stdio.h>

void notas()
{
    /*
    Escrever um programa que consiga simular a sequencia de rodadas
    de golpes, e ao final, dizer quem foi o vencedor (se houver um)
    
    regras: - No máximo 10 rodadas; - Cada rodada e representada por duas
    matrizes(a primeira apresenta o golpe do Luke e a segunda de Vader);
    - Cada matriz de golpe e 3*3
    - Para ser valida, todos os valores da matriz de golpe precisam ser
    iguais a 0, excetp a diagonal principal ou a secundaria, nas quais
    todos os valores precisam ser iguais a 1. Qualquer matriz que nao
    seja assim, sera invalida.
    - Uma matriz de golpe invalida significa que seu autor nao conseguiu
    atacar e pode receber dano se a matriz de golpe do adversario for
    valida;
    - Em rodadas que ambas as matrizes de golpes sao validas e com as
    diagonais iguais, ambos os guerreiros recebem os ataques.
    Se as duas matrizes forem validas e diferentes, nenhum dos guerreiros
    toma dano na rodada.
    quando um combatente é atingido por um golpe, o mesmo perde 15 
    pontos de vida.
    */
}

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
        
        for(iy = ny-1; iy > 0; iy-=1)
        {
            somaluketransversal2 += golpesluke[iy][ix];
            ix -= 1;
        }

        //scan vader
        for(iy = 0; iy < ny; iy++)
        {
            for(ix = 0; ix < nx; ix++)
            {
                scanf("%d", &golpesvader[iy][ix]);
            }
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
        
        for(iy = ny-1; iy > 0; iy-=1)
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
        printf("%d\n%d", vaderlife, lukelife);
        

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
        if(vaderlife == 0)
        {
            printf("Luke Skywalker venceu.\n");
            rodada += 10;
        }
        somaluke = 0, somaluketransversal1 = 0, somaluketransversal2 = 0;
        somavader = 0, somavadertransversal1 = 0, somavadertransversal2 = 0;
    }
    return 0;
}