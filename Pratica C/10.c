#include <stdio.h>
#include <math.h>

int main() {
    double raio, comprimento, area, volume;
    const double pi = 3.14;
    printf("Digite o raio da esfera: ");
    scanf("%lf", &raio);
    comprimento = 2 * pi * raio;
    printf("O comprimento da esfera é: %.2lf\n", comprimento);
    area = pi * raio * raio;
    printf("A área da esfera é: %.2lf\n", area);
    volume = (3.0 / 4.0) * pi * pow(raio, 3);
    printf("O volume da esfera é: %.2lf\n", volume);
    return 0;
}
