#include <stdio.h>

int main()
{
    double dollar_quotation, icms_rate, product_value, shipping_value;
    double converted_product_value, converted_shipping_value, total_value;
    double tax_value, icms_value, total_taxes_value, product_final_value;

    scanf("%lf%lf%lf%lf", &dollar_quotation, &icms_rate, &product_value, &shipping_value);

    converted_product_value = product_value * dollar_quotation;
    converted_shipping_value = shipping_value * dollar_quotation;
    total_value = converted_product_value + converted_shipping_value;

    if (product_value < 2500)
    {
        tax_value = total_value * 0.6;
        product_final_value = ((product_value * dollar_quotation) + (shipping_value * dollar_quotation) + (((product_value * dollar_quotation) + (shipping_value * dollar_quotation)) * 0.6)) / (1 - (icms_rate / 100));
        icms_value = product_final_value * (icms_rate / 100);
        total_taxes_value = tax_value + icms_value;
    }

    else
    {
        tax_value = converted_product_value * 0.6;
        product_final_value = (((product_value * dollar_quotation)  + (((product_value * dollar_quotation) * 0.6))) / (1 - (icms_rate / 100)));
        icms_value = product_final_value * (icms_rate / 100);
        total_taxes_value = tax_value + icms_value;
    }

    printf("%.2lf\n%.2lf\n%.2lf\n", dollar_quotation, converted_product_value, converted_shipping_value);
    printf("%.2lf\n%.2lf\n%.2lf\n", total_value, tax_value, icms_value);

    if (product_value >= 2500)
    {
        printf("%.2lf\n%.2lf\n", total_taxes_value, product_final_value + converted_shipping_value);
    }

    else
    {
        printf("%.2lf\n%.2lf\n", total_taxes_value, product_final_value);
    }
    if (product_value >= 2500)
    {
        printf("Impostos calculados sem o frete\n");
    }

    else
    {
        printf("Impostos calculados com o frete\n");
    }

    return 0;
}