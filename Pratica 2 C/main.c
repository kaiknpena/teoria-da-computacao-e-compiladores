#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void LerSequenciasDoTeclado(int *seqA, int *seqB, int *tamA, int *tamB) {
    printf("Sequência A: ");
    scanf("%d", tamA);
    for (int i = 0; i < *tamA; i++) {
        scanf("%d", &seqA[i]);
    }

    printf("Sequência B: ");
    scanf("%d", tamB);
    for (int i = 0; i < *tamB; i++) {
        scanf("%d", &seqB[i]);
    }
}

void LerSequenciasDoArquivo(FILE *arq, int *seqA, int *seqB, int *tamA, int *tamB) {
    fscanf(arq, "%d", tamA);
    for (int i = 0; i < *tamA; i++) {
        fscanf(arq, "%d", &seqA[i]);
    }

    fscanf(arq, "%d", tamB);
    for (int i = 0; i < *tamB; i++) {
        fscanf(arq, "%d", &seqB[i]);
    }
}

void GerarConjuntos(int *seqA, int *seqB, int *tamA, int *tamB, int *cjA, int *cjB) {
    int num, idxA = 0, idxB = 0;
    for (int i = 0; i < *tamA; i++) {
        num = seqA[i];
        int pertence = 0;
        for (int j = 0; j < idxA; j++) {
            if (cjA[j] == num) {
                pertence = 1;
                break;
            }
        }
        if (!pertence) {
            cjA[idxA] = num;
            idxA++;
        }
    }
    for (int i = 0; i < *tamB; i++) {
        num = seqB[i];
        int pertence = 0;
        for (int j = 0; j < idxB; j++) {
            if (cjB[j] == num) {
                pertence = 1;
                break;
            }
        }
        if (!pertence) {
            cjB[idxB] = num;
            idxB++;
        }
    }
    *tamA = idxA;
    *tamB = idxB;
}

void ConjuntoPotencia(int *cj, int tam, FILE *arq) {
    int numSubconjuntos = (int)pow(2, tam);
    for (int i = 0; i < numSubconjuntos; i++) {
        fprintf(arq, "{");
        for (int j = 0; j < tam; j++) {
            if (i & (1 << j)) {
                fprintf(arq, "%d ", cj[j]);
            }
        }
        fprintf(arq, "}\n");
    }
}

void ConjuntoProprio(int *cj, int tam, FILE *arq) {
    for (int i = 1; i < tam; i++) {
        ConjuntoPotencia(cj, i, arq);
    }
}

void UniaoConjuntos(int *cjA, int tamA, int *cjB, int tamB, FILE *arq) {
    int *uniao = (int *)malloc((tamA + tamB) * sizeof(int));
    int tamUniao = 0;

    for (int i = 0; i < tamA; i++) {
        uniao[tamUniao] = cjA[i];
        tamUniao++;
    }

    for (int i = 0; i < tamB; i++) {
        int pertence = 0;
        for (int j = 0; j < tamA; j++) {
            if (cjB[i] == cjA[j]) {
                pertence = 1;
                break;
            }
        }

        if (!pertence) {
            uniao[tamUniao] = cjB[i];
            tamUniao++;
        }
    }

    for (int i = 0; i < tamUniao; i++) {
        fprintf(arq, "%d ", uniao[i]);
    }

    fprintf(arq, "\n");
    free(uniao);
}

void IntersecaoConjuntos(int *cjA, int tamA, int *cjB, int tamB, FILE *arq) {
    int *intersecao = (int *)malloc(tamA * sizeof(int));
    int tamIntersecao = 0;

    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            if (cjA[i] == cjB[j]) {
                intersecao[tamIntersecao] = cjA[i];
                tamIntersecao++;
                break;
            }
        }
    }

    for (int i = 0; i < tamIntersecao; i++) {
        fprintf(arq, "%d ", intersecao[i]);
    }

    fprintf(arq, "\n");
    free(intersecao);
}

void DiferencaConjuntos(int *cjA, int tamA, int *cjB, int tamB, FILE *arq) {
    int *diferenca = (int *)malloc(tamA * sizeof(int));
    int tamDiferenca = 0;

    for (int i = 0; i < tamA; i++) {
        int pertence = 1;
        for (int j = 0; j < tamB; j++) {
            if (cjA[i] == cjB[j]) {
                pertence = 0;
                break;
            }
        }

        if (pertence) {
            diferenca[tamDiferenca] = cjA[i];
            tamDiferenca++;
        }
    }

    for (int i = 0; i < tamDiferenca; i++) {
        fprintf(arq, "%d ", diferenca[i]);
    }

    fprintf(arq, "\n");
    free(diferenca);
}

void ProdutoCartesiano(int *cjA, int tamA, int *cjB, int tamB, FILE *arq) {
    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            fprintf(arq, "(%d, %d) ", cjA[i], cjB[j]);
        }
        fprintf(arq, "\n");
    }
}

int main() {
    int seqA[100], seqB[100];
    int tamA = 0, tamB = 0;

    printf("Escolha uma opção:\n");
    printf("1. Ler sequências do teclado e salvar no arquivo\n");
    printf("2. Ler sequências do arquivo\n");
    printf("3. Sair\n");

    int opcao;
    scanf("%d", &opcao);

    if (opcao == 1) {
        FILE *arq = fopen("sequencias.txt", "w");

        if (arq == NULL) {
            printf("Erro ao abrir o arquivo para escrita.\n");
            return 1;
        }

        LerSequenciasDoTeclado(seqA, seqB, &tamA, &tamB);

        fprintf(arq, "%d ", tamA);
        for (int i = 0; i < tamA; i++) {
            fprintf(arq, "%d ", seqA[i]);
        }

        fprintf(arq, "\n%d ", tamB);
        for (int i = 0; i < tamB; i++) {
            fprintf(arq, "%d ", seqB[i]);
        }

        fclose(arq);
    } else if (opcao == 2) {
        FILE *arq = fopen("sequencias.txt", "r");

        if (arq == NULL) {
            printf("Erro ao abrir o arquivo para leitura.\n");
            return 1;
        }

        LerSequenciasDoArquivo(arq, seqA, seqB, &tamA, &tamB);

        fclose(arq);
    } else if (opcao == 3) {
        return 0;
    }

    int cjA[100], cjB[100];
    int tamCjA = tamA, tamCjB = tamB;

    GerarConjuntos(seqA, seqB, &tamCjA, &tamCjB, cjA, cjB);

    FILE *arq = fopen("conjuntos.txt", "w");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    fprintf(arq, "%d ", tamCjA);
    for (int i = 0; i < tamCjA; i++) {
        fprintf(arq, "%d ", cjA[i]);
    }

    fprintf(arq, "\n%d ", tamCjB);
    for (int i = 0; i < tamCjB; i++) {
        fprintf(arq, "%d ", cjB[i]);
    }

    ConjuntoPotencia(cjA, tamCjA, arq);
    ConjuntoPotencia(cjB, tamCjB, arq);

    ConjuntoProprio(cjA, tamCjA, arq);
    ConjuntoProprio(cjB, tamCjB, arq);

    UniaoConjuntos(cjA, tamCjA, cjB, tamCjB, arq);
    IntersecaoConjuntos(cjA, tamCjA, cjB, tamCjB, arq);
    DiferencaConjuntos(cjA, tamCjA, cjB, tamCjB, arq);
    DiferencaConjuntos(cjB, tamCjB, cjA, tamCjA, arq);

    ProdutoCartesiano(cjA, tamCjA, cjB, tamCjB, arq);
    ProdutoCartesiano(cjB, tamCjB, cjA, tamCjA, arq);

    fclose(arq);
    printf("Operações concluídas. Resultados salvos em 'conjuntos.txt'.\n");

    return 0;
}