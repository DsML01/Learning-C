    #include <stdio.h>
    #include <stdlib.h>

    int soma_vetor_com_escalar(int v[], int n, int escalar)
    {
        for(int i = 0; i < n; i++)
        {
            v[i] += escalar;
        }
    }

    //CONST transforma uma variável em read only, nao permitindo que ela seja modificada.
    //seu proposito eh evitar alguns erros que possam vir a ocorrer
    void print_vetor(const int *v, int n)
    {
        for(int i = 0; i < n; i++)
        {
            printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
        }
        puts("");
    }

    void desalocar_array (int **v)
    {
        free(*v);
        *v = NULL;
    }

    int main()
    {
        puts("VETOR ESTATICO NA STACK");
        int ve[5] = {10, 20, 30, 40, 50};

        print_vetor(ve, 5);
        soma_vetor_com_escalar(ve, 5, 9);
        print_vetor(ve, 5);

        puts("VETOR DINAMICO NA HEAP");
        int *vh = (int *) calloc(5, sizeof(int));

        for(int i = 0; i < 5; i++)
        {
            vh[i] = i * 100;
        }
        
        print_vetor(vh, 5);
        soma_vetor_com_escalar(vh, 5, 9);
        print_vetor(vh, 5);
        
        // desalocando o array DINAMICO
        /*free(vh);
        vh = NULL;*/
        puts("ANTES DA FUNCAO DE DESALOCAR O VETOR DINAMICO");
        printf("&vh = %p, vh = %p\n", &vh, vh);

        desalocar_array (&vh);

        puts("\nDEPOIS DA FUNCAO DE DESALOCAR O VETOR DINAMICO");
        printf("&vh = %p, vh = %p\n", &vh, vh);

        return 0;
    }