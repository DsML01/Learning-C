#include <stdio.h>

int main() {
    int dol,icms,valor,frete;
    
    scanf("%d%d%d%d", &dol,&icms,&valor,&frete);

    int valorbr = valor * dol, fretebr = frete * dol, valortotal = (fretebr + valorbr);
    int roubo = valorbr * 0.6, valorfinal = (valorbr + fretebr + roubo) / ( 1 - icms);
    int total = 
    
    printf("%d", dol);
    printf("%d", valorbr);
    printf("%d", fretebr);
    printf("%d", valortotal);
    printf("%d", roubo);
    //printf("%d",ICMS);
    //printf("%d", roubo + icms);
    printf ("%d");
    
    
    return 0;
}