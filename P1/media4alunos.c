#include <stdio.h>

int main(){
    int bimestres = 4, alunos = 4;
    
    double notasAlunos[alunos][bimestres];
    double mediasAlunos[alunos];
    
    double media = 0;
    
    printf("Insira as 4 notas do aluno 1:\n");
        
        for(int aluno = 0; aluno < alunos; aluno++){
            
            for(int notas = 0; notas < bimestres; notas++){
                scanf("%lf", &notasAlunos[aluno][notas]);  
                media += notasAlunos[aluno][notas];
            }
            mediasAlunos[aluno] = media/bimestres;
            media = 0;
            if(aluno == alunos - 1) printf("\n");
            else printf("Insira as 4 notas do aluno %d:\n", aluno+2);
        } 
        
    
    
    for(int aluno = 0; aluno < alunos; aluno++){
        printf("A media do aluno %d eh de %.2lf\n", aluno+1,mediasAlunos[aluno]);
    }
    
        
    
}