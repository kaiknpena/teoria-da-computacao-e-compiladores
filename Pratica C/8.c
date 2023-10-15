#include <stdio.h>

int main() {
    double peso, novoPeso;
    printf("Digite o peso da pessoa: ");
    scanf("%lf", &peso);
    novoPeso = peso + (peso * 0.15);
    printf("Se a pessoa engordar 15%%, o novo peso será: %.2lf\n", novoPeso);
    novoPeso = peso - (peso * 0.20);
    printf("Se a pessoa emagrecer 20%%, o novo peso será: %.2lf\n", novoPeso);
    return 0;
}
