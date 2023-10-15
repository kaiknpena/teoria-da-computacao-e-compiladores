#include <stdio.h>

int main() {
    double temperaturaCelsius, temperaturaFahrenheit;
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%lf", &temperaturaCelsius);
    temperaturaFahrenheit = (temperaturaCelsius * 1.8) + 32;
    printf("A temperatura em graus Fahrenheit é: %.2lf°F\n", temperaturaFahrenheit);
    return 0;
}
