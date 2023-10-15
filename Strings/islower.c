#include <stdio.h>
#include <ctype.h>

int main() {
    char caractere = 'b';

    if (islower(caractere)) {
        printf("%c é uma letra minúscula.\n", caractere);
    } else {
        printf("%c não é uma letra minúscula.\n", caractere);
    }

    return 0;
}
