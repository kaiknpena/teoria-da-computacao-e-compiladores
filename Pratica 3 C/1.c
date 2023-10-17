#include <stdio.h>

void naoRecursivo(int limite) {
    for (int n = 0; n <= limite; n++) {
        int resultado;

        if (n % 2 == 0) {
            resultado = -n / 2;
        } else {
            resultado = n / 2 + 1;
        }

        printf("[%d, %d], ", n, resultado);
    }
    printf("\n");
}

void recursivo(int n, int limite) {
    if (n <= limite) {
        int resultado;

        if (n % 2 == 0) {
            resultado = -n / 2;
        } else {
            resultado = n / 2 + 1;
        }

        printf("[%d, %d], ", n, resultado);

        recursivo(n + 1, limite);
    } else {
        printf("\n");
    }
}

int main() {
    int limite;

    printf("Informe o limite: ");
    scanf("%d", &limite);

    printf("Não Recursivo: ");
    naoRecursivo(limite);

    printf("Recursivo: ");
    recursivo(0, limite);

    return 0;
}