#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
    char cpf[12];
    char nome[50];
    double salario;
};

struct Pessoa *alocarMemoria(int n) {
    struct Pessoa *array = (struct Pessoa *)calloc(n, sizeof(struct Pessoa));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return array;
}

void preencherVetor(struct Pessoa *array, int n) {
    for (int i = 0; i < n; i++) {
        sprintf(array[i].cpf, "CPF%d", i + 1);
        sprintf(array[i].nome, "Pessoa%d", i + 1);
        array[i].salario = 1000.0 + i * 100.0;
    }
}

void imprimirVetor(struct Pessoa *array, int n) {
    printf("Vetor de Pessoas:\n");
    for (int i = 0; i < n; i++) {
        printf("CPF: %s, Nome: %s, Salário: %.2lf\n", array[i].cpf, array[i].nome, array[i].salario);
    }
}

void liberarMemoria(struct Pessoa *array) {
    free(array);
}

int main() {
    struct Pessoa *pessoas;
    int n;

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &n);

    pessoas = alocarMemoria(n);
    preencherVetor(pessoas, n);
    imprimirVetor(pessoas, n);
    liberarMemoria(pessoas);

    return 0;
}