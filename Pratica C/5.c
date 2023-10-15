#include <stdio.h>

int main() {
    double diagonalMaior, diagonalMenor, area;
    printf("Digite o valor da diagonal maior do losango: ");
    scanf("%lf", &diagonalMaior);
    printf("Digite o valor da diagonal menor do losango: ");
    scanf("%lf", &diagonalMenor);
    area = (diagonalMaior * diagonalMenor) / 2.0;
    printf("A área do losango é: %.2lf unidades quadradas\n", area);
    return 0;
}
