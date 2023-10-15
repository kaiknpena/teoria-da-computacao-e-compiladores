#include <stdio.h>
#include <stdlib.h>

int *alocarMemoria(int n) {
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return array;
}

void preencherVetor(int *array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = i * 10;
    }
}

void imprimirVetor(int *array, int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void liberarMemoria(int *array) {
    free(array);
}

int main() {
    int *array, n;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    array = alocarMemoria(n);
    preencherVetor(array, n);
    imprimirVetor(array, n);
    liberarMemoria(array);

    return 0;
}