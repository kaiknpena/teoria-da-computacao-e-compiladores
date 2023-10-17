#include <stdio.h>

int sucessor(int n) {
    return n + 1;
}

int menorQue(int i) {
    if (i < 0) {
        printf("O valor de i deve ser não negativo.\n");
        return -1;
    }

    int conjuntoMQ[i + 1][2];  // Array para armazenar os pares [n, m]

    conjuntoMQ[0][0] = 0;
    conjuntoMQ[0][1] = 1;

    for (int k = 1; k <= i; k++) {
        conjuntoMQ[k][0] = k;
        conjuntoMQ[k][1] = sucessor(conjuntoMQ[k - 1][1]);
    }

    printf("Conjunto MQ%d:\n", i);
    for (int k = 0; k <= i; k++) {
        printf("[%d, %d] ", conjuntoMQ[k][0], conjuntoMQ[k][1]);
    }

    printf("\n");

    return 0;
}

int main() {
    int i;

    printf("Informe o valor de i: ");
    scanf("%d", &i);

    menorQue(i);

    return 0;
}