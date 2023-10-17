#include <stdio.h>

#define NUM_NODOS 4

int grafo[NUM_NODOS][NUM_NODOS];

void inicializarGrafo() {
    for (int i = 0; i < NUM_NODOS; i++) {
        for (int j = 0; j < NUM_NODOS; j++) {
            grafo[i][j] = 0;
        }
    }
}

void adicionarAresta(int origem, int destino, int peso) {
    grafo[origem][destino] = peso;
}

int calcularComprimentoCaminhoRecursivo(int origem, int destino) {
    if (origem == destino) {
        return 0;
    }

    int menorCaminho = -1;
    for (int i = 0; i < NUM_NODOS; i++) {
        if (grafo[origem][i] > 0) {
            int caminho = calcularComprimentoCaminhoRecursivo(i, destino);
            if (caminho >= 0) {
                if (menorCaminho == -1 || caminho + grafo[origem][i] < menorCaminho) {
                    menorCaminho = caminho + grafo[origem][i];
                }
            }
        }
    }

    return menorCaminho;
}

int temCiclos(int origem, int visitados[NUM_NODOS]) {
    visitados[origem] = 1;
    for (int i = 0; i < NUM_NODOS; i++) {
        if (grafo[origem][i] > 0) {
            if (visitados[i] == 1) {
                return 1; // Encontrou um ciclo
            }
            if (visitados[i] == 0 && temCiclos(i, visitados)) {
                return 1; // Ciclo encontrado em um nó adjacente
            }
        }
    }
    visitados[origem] = 2;
    return 0;
}

int grauEntrada(int nodo) {
    int entrada = 0;
    for (int i = 0; i < NUM_NODOS; i++) {
        if (grafo[i][nodo] > 0) {
            entrada++;
        }
    }
    return entrada;
}

int grauSaida(int nodo) {
    int saida = 0;
    for (int i = 0; i < NUM_NODOS; i++) {
        if (grafo[nodo][i] > 0) {
            saida++;
        }
    }
    return saida;
}

int main() {
    int origem, destino;

    inicializarGrafo();

    adicionarAresta(0, 1, 10);
    adicionarAresta(1, 2, 15);
    adicionarAresta(2, 3, 20);
    adicionarAresta(3, 0, 5);

    printf("Informe o nodo de origem: ");
    scanf("%d", &origem);
    printf("Informe o nodo de destino: ");
    scanf("%d", &destino);

    int comprimentoCaminho = calcularComprimentoCaminhoRecursivo(origem, destino);

    if (comprimentoCaminho >= 0) {
        printf("O comprimento do caminho de %d para %d é %d\n", origem, destino, comprimentoCaminho);
    } else {
        printf("Não existe um caminho de %d para %d\n", origem, destino);
    }

    int visitados[NUM_NODOS] = {0};
    if (temCiclos(0, visitados)) {
        printf("O grafo contém ciclos.\n");
    } else {
        printf("O grafo não contém ciclos.\n");
    }

    for (int i = 0; i < NUM_NODOS; i++) {
        printf("Grau de entrada do nodo %d: %d\n", i, grauEntrada(i));
    }

    for (int i = 0; i < NUM_NODOS; i++) {
        printf("Grau de saída do nodo %d: %d\n", i, grauSaida(i));
    }

    return 0;
}