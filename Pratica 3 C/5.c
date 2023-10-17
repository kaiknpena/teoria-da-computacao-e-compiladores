#include <stdio.h>

#define NUM_CIDADES 4

int matrizDistancias[NUM_CIDADES][NUM_CIDADES];

void inicializar() {
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            matrizDistancias[i][j] = 0;
        }
    }
}

void inserir(int cidade1, int cidade2, int distancia) {
    matrizDistancias[cidade1][cidade2] = distancia;
    matrizDistancias[cidade2][cidade1] = distancia;
}

int contar() {
    int count = 0;
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = i + 1; j < NUM_CIDADES; j++) {
            if (matrizDistancias[i][j] > 0) {
                count++;
            }
        }
    }
    return count;
}

void imprimir() {
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            printf("%d\t", matrizDistancias[i][j]);
        }
        printf("\n");
    }
}

int distanciaRecursiva(int cidade1, int cidade2) {
    if (matrizDistancias[cidade1][cidade2] > 0) {
        return matrizDistancias[cidade1][cidade2];
    }
    return 0;
}

int main() {
    inicializar();
    inserir(0, 1, 10);
    inserir(1, 2, 20);
    inserir(2, 3, 15);
    inserir(0, 3, 5);

    printf("Matriz de distâncias:\n");
    imprimir();

    int cidade1, cidade2;
    printf("\nInforme o número da primeira cidade: ");
    scanf("%d", &cidade1);
    printf("Informe o número da segunda cidade: ");
    scanf("%d", &cidade2);

    int distancia = distanciaRecursiva(cidade1, cidade2);
    if (distancia > 0) {
        printf("Distância entre as cidades %d e %d: %d\n", cidade1, cidade2, distancia);
    } else {
        printf("Não há estrada ligando as cidades %d e %d.\n", cidade1, cidade2);
    }

    int estradas = contar();
    printf("Número total de estradas: %d\n", estradas);

    return 0;
}