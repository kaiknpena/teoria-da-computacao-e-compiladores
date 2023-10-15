#include <stdio.h>

int main() {
    double salario, novoSalario;
    printf("Digite o salário atual do funcionário: R$ ");
    scanf("%lf", &salario);
    novoSalario = salario * 1.25;
    printf("O novo salário do funcionário é: R$ %.2lf\n", novoSalario);
    return 0;
}
