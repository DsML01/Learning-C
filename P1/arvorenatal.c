#include <stdio.h>

int analise(double value[],double amount[],double total, int i)
{
    if (i == 3)
    {
        printf("%.2lf\n%.2lf\n", total, total/20);
    }
    else 
    {
        scanf("%lf", &amount[i]);
        scanf("%lf", &value[i]);

        total += value[i]*amount[i];

        return analise(value, amount, total, i+1);
    }
}

int main (){
    double tree, value[3], amount[3];

    scanf("%lf", &tree);

    analise(value, amount, tree, 0);

    return 0;
}