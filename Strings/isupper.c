#include <stdio.h>
#include <ctype.h>

int main() {
    char caractere = 'B';

    if (isupper(caractere)) {
        printf("%c é uma letra maiúscula.\n", caractere);
    } else {
        printf("%c não é uma letra maiúscula.\n", caractere);
    }

    return 0;
}
