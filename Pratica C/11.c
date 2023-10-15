#include <stdio.h>

int main() {
    int numero;
    printf("Informe um número: ");
    scanf("%d", &numero);
    printf("Tabuada de multiplicação para %d:\n", numero);
    for (int i = 0; i <= 10; i++) {
        int resultado = numero * i;
        printf("%d x %d = %d\n", numero, i, resultado);
    }
    return 0;
}
