#include <stdio.h>

int main() {
    double cotacaoDolar, valorDolares;
    double valorReais;

    printf("Digite a cotação do dólar em reais: ");
    scanf("%lf", &cotacaoDolar);

    printf("Digite o valor em dólares que você possui: ");
    scanf("%lf", &valorDolares);

    valorReais = valorDolares * cotacaoDolar;

    printf("O valor em reais é: %.2lf\n", valorReais);

    return 0;
}
