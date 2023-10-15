#include <stdio.h>

int main() {
    double salarioMinimo, salarioFuncionario;
    double quantSalariosMinimos;
    printf("Digite o valor do salário mínimo: R$ ");
    scanf("%lf", &salarioMinimo);
    printf("Digite o valor do salário do funcionário: R$ ");
    scanf("%lf", &salarioFuncionario);
    quantSalariosMinimos = salarioFuncionario / salarioMinimo;
    printf("O funcionário recebe %.2lf salários mínimos.\n", quantSalariosMinimos);
    return 0;
}
