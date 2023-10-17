#include <stdio.h>

int sucessor(int n) {
    return n + 1;
}

int soma(int m, int n) {
    if (n == 0) {
        return m;
    } else {
        return soma(sucessor(m), n - 1);
    }
}

int main() {
    int m, n;

    printf("Informe o primeiro número: ");
    scanf("%d", &m);

    printf("Informe o segundo número: ");
    scanf("%d", &n);

    int resultado = soma(m, n);

    printf("%d + %d = %d\n", m, n, resultado);

    return 0;
}