#include <stdio.h>

int somaNaturais(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + somaNaturais(n - 1);
    }
}

int main() {
    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int resultado = somaNaturais(n);
    printf("A soma dos primeiros %d números naturais é: %d\n", n, resultado);

    return 0;
}
