#include <stdio.h>

int analise(char gabarito[], double notas[], char respostas[], double nota, int n, int ia, int i)
{
    if(i == n) 
    {
        notas[ia] = nota;
        return 0;
    }

    else
    {
        if(gabarito[i] == respostas[i]) return analise(gabarito, notas, respostas, nota + 1, n, ia, i + 1);
        else return analise(gabarito, notas, respostas, nota, n, ia, i + 1);
    }
}

//PRECISO CONSEGUIR FAZER A MODAAAAAAAAA
int maior(int contsort[], int greatest, int greatestindex, int i, int n)
{
    if(i == n)
    {   
        printf("%d.0", greatestindex);
        
        return 0;
    }
    else 
    {
        if(greatest < contsort[i]) 
        {
            greatest = contsort [i];
            greatestindex = i;
        }
        
        return maior(contsort, greatest, greatestindex, i + 1, n);
    }
}

/*void imprimir(int contsort[], int i, int n)
{
    if(i == n) return;
    
    else
    {
        printf("%d\n",contsort[i]);
        return imprimir(contsort, i + 1, n);
    }
}*/


int countsort(double notas[], int contsort[], int i, int n)
{
    if(i == n)
    {
        int greatest = contsort[0];
        maior(contsort,greatest, 0, 0, 11);
        //imprimir(contsort, 0, 11);
        return 0;
    }
    else
    {
        if(notas[i] == 0.0) contsort[0] += 1;

        else if(notas[i] == 1.0) contsort[1] += 1;
       
        else if(notas[i] == 2.0) contsort[2] += 1;
       
        else if(notas[i] == 3.0) contsort[3] += 1;
        
        else if(notas[i] == 4.0) contsort[4] += 1;
  
        else if(notas[i] == 5.0) contsort[5] += 1;
   
        else if(notas[i] == 6.0) contsort[6] += 1;
     
        else if(notas[i] == 7.0) contsort[7] += 1;
    
        else if(notas[i] == 8.0) contsort[8] += 1;
  
        else if(notas[i] == 9.0) contsort[9] += 1;
   
        else if(notas[i] == 10.0) contsort[10] += 1;
   
        return countsort(notas, contsort, i+1, n);
    }
}

void porcentagem(double notas[], int i, int n, double passantes)
{
    if(i == n)
    {
        printf("%.1lf%%\n", (passantes/n)*100);
        int contsort[11] = {0,0,0,0,0,0,0,0,0,0,0};
        countsort(notas, contsort, 0, n);
        return;
    }
    else
    {
        if(notas[i] >=6 ) passantes += 1;

        return porcentagem(notas, i + 1, n, passantes);
    }
}

void printar(double notas[], int i, int n)
{
    if(i == n)
    {
        porcentagem(notas, 0, n, 0);
        return;
    }
    else
    {
        printf("%d %.1lf\n", i+1, notas[i]);

        return printar(notas, i + 1, n);
    }
}

void ler(char gabarito[], double notas[], int ia)
{
    int aluno;
    
    scanf("%d", &aluno);
    
    if(aluno == 9999)
    {
        printar(notas, 0, ia + 1);
        return;
    }

    else
    {
        char respostas[10];

        scanf("%s", respostas);

        ia += 1;

        analise(gabarito, notas, respostas, 0, 10, ia, 0);

        ler(gabarito, notas, ia);

    }
}

int main () 
{
    char gabarito[10];

    double notas[1000];

    scanf("%s", gabarito);

    ler(gabarito, notas, -1);

    return 0;
}