#include <stdio.h>

int main() {
    int anoNascimento, anoAtual;
    int idadeAtual, idade2050;

    printf("Digite o ano de nascimento: ");
    scanf("%d", &anoNascimento);

    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);

    idadeAtual = anoAtual - anoNascimento;
    idade2050 = 2050 - anoNascimento;

    printf("A idade da pessoa no ano atual é: %d anos\n", idadeAtual);
    printf("A idade da pessoa em 2050 será: %d anos\n", idade2050);

    return 0;
}