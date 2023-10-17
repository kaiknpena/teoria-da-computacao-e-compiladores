#include <stdio.h>

int sucessor(int n) {
    return n + 1;
}

int main() {
    int i;

    printf("Informe o valor de i: ");
    scanf("%d", &i);

    if (i < 0) {
        printf("O valor de i deve ser não negativo.\n");
        return 1;
    }

    int conjuntoMQ[i + 1][2];  // Array para armazenar os pares [n, m]

    conjuntoMQ[0][0] = 0;
    conjuntoMQ[0][1] = 1;

    printf("Conjunto MQ0:\n[0, 1]\n");

    for (int k = 1; k <= i; k++) {
        conjuntoMQ[k][0] = k;
        conjuntoMQ[k][1] = sucessor(conjuntoMQ[k - 1][1]);

        printf("Conjunto MQ%d:\n", k);
        for (int j = 0; j <= k; j++) {
            printf("[%d, %d] ", conjuntoMQ[j][0], conjuntoMQ[j][1]);
        }
        printf("\n");
    }

    return 0;
}