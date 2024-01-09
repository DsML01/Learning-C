#include <stdio.h>

int main() {
    double dol,taxaicms,valor,frete;
    
    scanf("%lf%lf%lf%lf", &dol,&taxaicms,&valor,&frete);

    double icms = taxaicms/100;

    double valorbr = valor * dol, fretebr = frete * dol, valortotal = (fretebr + valorbr);
    double imposto, valorfinal, valoricms, impostototal,totaltotal;
    
    printf("%.2lf\n", dol);
    printf("%.2lf\n", valorbr);
    printf("%.2lf\n", fretebr);
    printf("%.2lf\n", valortotal);
    if (valor<2500) {
        imposto = valortotal * 0.6;
        valorfinal = (valorbr + fretebr + imposto) / (1 - (icms));
        valoricms = valorfinal * icms;
        impostototal = imposto + valoricms;
        totaltotal = valortotal + impostototal;
        printf("%.2lf\n", imposto);
        printf("%.2lf\n", valoricms);
        printf("%.2lf\n", impostototal);
        printf("%.2lf\n", totaltotal);
        printf("Impostos calculados com o frete\n");
    }
    else {
        imposto = valorbr * 0.6;
        valorfinal = (valorbr + imposto)/(1 - icms);
        valoricms = valorfinal * icms;
        impostototal = imposto + valoricms;
        totaltotal = valortotal + impostototal;
        printf("%.2lf\n", imposto);
        printf("%.2lf\n", valoricms);
        printf("%.2lf\n", impostototal);
        printf("%.2lf\n", totaltotal);
        printf("Impostos calculados sem o frete\n");
    }
    return 0;
}