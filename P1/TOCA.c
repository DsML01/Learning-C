    #include <stdio.h>

    int nexti(int holes[], int i, int n)
    {
        if(i == n) return -1;

        if(holes[i] == -1) return nexti(holes, i+1, n);

        return i;

    }

    int visita(int holes[], int i, int n, int tocas)
    {
        if(i == -1)
        {
            printf("%d", tocas);
            return 0;
        }
        int nexthole;
        if(holes[i] == -1)
        {
            tocas += 1;
            nexthole = nexti(holes, i, n);
        }
        else
        {
            nexthole = holes[i];
            
            if(nexthole >= n) nexthole = 0;

            holes[i] = -1;
        }
        return visita(holes, nexthole, n, tocas);
    }

    void ler(int holes[], int i, int n)
    {
        if(i == n)
        {
            visita(holes, 0, n, 0);
            return;
        }
        scanf("%d", &holes[i]);
        ler(holes, i+1, n);

    }

    int main()
    {
        int n;
        scanf("%d", &n);
        int holes[n];

        ler(holes, 0, n);
        return 0;
    }