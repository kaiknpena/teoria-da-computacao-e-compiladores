#include <stdio.h>

int main() {
    double numeros[3];
    double soma = 0;

    for (int i = 0; i < 3; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%lf", &numeros[i]);
        soma += numeros[i];
    }

    double media = soma / 3.0;

    printf("A média dos números é: %lf\n", media);

    return 0;
}
