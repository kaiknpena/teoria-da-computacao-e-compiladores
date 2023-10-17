#include <stdio.h>
#include <stdlib.h>

int tamanhoRecursivo(const char *str) {
    if (str[0] == '\0') {
        return 0;
    } else {
        return 1 + tamanhoRecursivo(str + 1);
    }
}

void inverterRecursivo(const char *str, char *reverso, int *indice) {
    if (str[0] == '\0') {
        reverso[*indice] = '\0';
    } else {
        inverterRecursivo(str + 1, reverso, indice);
        reverso[(*indice)++] = str[0];
    }
}

int main() {
    FILE *arquivo = fopen("texto.txt", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    char str[1000];
    if (fgets(str, sizeof(str), arquivo) != NULL) {
        int tamanho = tamanhoRecursivo(str);

        FILE *tempFile = tmpfile();
        if (tempFile == NULL) {
            printf("Erro ao criar arquivo temporário.\n");
            return 1;
        }

        char reverso[1000];
        int indice = 0;
        inverterRecursivo(str, reverso, &indice);
        fputs(reverso, tempFile);

        rewind(arquivo);
        fprintf(arquivo, "Tamanho da string: %d\n", tamanho);

        int c;
        while ((c = fgetc(tempFile)) != EOF) {
            fputc(c, arquivo);
        }

        fclose(arquivo);
        fclose(tempFile);

        printf("Tamanho da string: %d\n", tamanho);
        printf("String invertida: %s\n", reverso);
    } else {
        printf("Erro ao ler a string do arquivo.\n");
    }

    return 0;
}