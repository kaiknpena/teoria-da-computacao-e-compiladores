#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Veiculo {
    char chassi[20];
    char marca[50];
    char modelo[50];
    double preco;
};

struct Veiculo *alocarMemoria(int tamanho) {
    struct Veiculo *vetor = (struct Veiculo *)malloc(tamanho * sizeof(struct Veiculo));
    if (vetor == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return vetor;
}

void preencherVeiculos(struct Veiculo *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        sprintf(vetor[i].chassi, "CHASSI%d", i + 1);
        sprintf(vetor[i].marca, "Marca%d", i + 1);
        sprintf(vetor[i].modelo, "Modelo%d", i + 1);
        vetor[i].preco = 10000.0 + i * 1000.0;
    }
}

void imprimirVeiculos(struct Veiculo *vetor, int tamanho) {
    printf("Veículos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Chassi: %s, Marca: %s, Modelo: %s, Preço: %.2lf\n",
               vetor[i].chassi, vetor[i].marca, vetor[i].modelo, vetor[i].preco);
    }
}

struct Veiculo *realocarMemoria(struct Veiculo *vetor, int tamanho_atual, int novo_tamanho) {
    vetor = (struct Veiculo *)realloc(vetor, novo_tamanho * sizeof(struct Veiculo));
    if (vetor == NULL) {
        printf("Falha na realocação de memória.\n");
        exit(1);
    }
    return vetor;
}

int main() {
    struct Veiculo *veiculos;
    int tamanho_inicial, novo_tamanho;

    printf("Digite o tamanho inicial do vetor de veículos: ");
    scanf("%d", &tamanho_inicial);

    veiculos = alocarMemoria(tamanho_inicial);
    preencherVeiculos(veiculos, tamanho_inicial);
    imprimirVeiculos(veiculos, tamanho_inicial);

    printf("Digite o novo tamanho do vetor de veículos: ");
    scanf("%d", &novo_tamanho);

    veiculos = realocarMemoria(veiculos, tamanho_inicial, novo_tamanho);
    preencherVeiculos(veiculos + tamanho_inicial, novo_tamanho - tamanho_inicial);
    imprimirVeiculos(veiculos, novo_tamanho);

    free(veiculos);

    return 0;
}