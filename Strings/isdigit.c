#include <stdio.h>
#include <ctype.h>

int main() {
    char caractere = '5';

    if (isdigit(caractere)) {
        printf("%c é um dígito.\n", caractere);
    } else {
        printf("%c não é um dígito.\n", caractere);
    }

    return 0;
}
