#include <stdio.h>
int repeticao(dias,metaprogramas,metalinhas,mostproductiveday,dayweare,maiorqtdlinhas){
    if (dias==0) {
        printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: %d\n",metaprogramas);
        printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: %d\n", metalinhas);
        if (mostproductiveday==1) {
            printf ("DIA QUE MAIS PRODUZIU: DOMINGO\n");
        }
        else if (mostproductiveday==2) {
            printf ("DIA QUE MAIS PRODUZIU: SEGUNDA\n");
        }
        else if (mostproductiveday==3) {
            printf ("DIA QUE MAIS PRODUZIU: TERCA\n");
        }
        else if (mostproductiveday==4) {
            printf ("DIA QUE MAIS PRODUZIU: QUARTA\n");
        }
        else if (mostproductiveday==5) {
            printf ("DIA QUE MAIS PRODUZIU: QUINTA\n");
        }
        else if (mostproductiveday==6) {
            printf ("DIA QUE MAIS PRODUZIU: SEXTA\n");
        }
        else if (mostproductiveday==7) {
            printf ("DIA QUE MAIS PRODUZIU: SABADO\n");
        }
        
    }
    else {
        int qtdprogramas,qtdlinhas;
        scanf("%d%d",&qtdprogramas,&qtdlinhas);
        if (qtdprogramas>=5){
            metaprogramas=metaprogramas+1;
            if (qtdlinhas>=100){
                metalinhas=metalinhas+1;
                if (qtdlinhas>maiorqtdlinhas) {
                    mostproductiveday=dayweare;
                    maiorqtdlinhas=qtdlinhas;
                    return repeticao(dias-1,metaprogramas,metalinhas,mostproductiveday,dayweare+1,maiorqtdlinhas);
                }
                else {
                    return repeticao(dias-1,metaprogramas,metalinhas,mostproductiveday,dayweare+1,maiorqtdlinhas);
                }
            }
            else {
                if (qtdlinhas>maiorqtdlinhas) {
                    mostproductiveday=dayweare;
                    maiorqtdlinhas=qtdlinhas;
                    return repeticao(dias-1,metaprogramas,metalinhas,mostproductiveday,dayweare+1,maiorqtdlinhas);
                }
                else {
                    return repeticao(dias-1,metaprogramas,metalinhas,mostproductiveday,dayweare+1,maiorqtdlinhas);
                }
            }
        }
        else {
            if (qtdlinhas>=100) {
                metalinhas=metalinhas+1;
                if (qtdlinhas>maiorqtdlinhas) {
                    mostproductiveday=dayweare;
                    maiorqtdlinhas=qtdlinhas;
                    return repeticao(dias-1,metaprogramas,metalinhas,mostproductiveday,dayweare+1,maiorqtdlinhas);
                }
                else {
                    return repeticao(dias-1,metaprogramas,metalinhas,mostproductiveday,dayweare+1,maiorqtdlinhas);
                }
            }
            else {
                if (qtdlinhas>maiorqtdlinhas) {
                    mostproductiveday=dayweare;
                    maiorqtdlinhas=qtdlinhas;
                    return repeticao(dias-1,metaprogramas,metalinhas,mostproductiveday,dayweare+1,maiorqtdlinhas);
                }
                else {
                    return repeticao(dias-1,metaprogramas,metalinhas,mostproductiveday,dayweare+1,maiorqtdlinhas);
                }
            }
        }
    }
    
}
int main (){
    repeticao(7,0,0,1,1,0);
    
    return 0;
}