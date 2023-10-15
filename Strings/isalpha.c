#include <stdio.h>
#include <ctype.h>

int main() {
    char caractere = 'A';

    if (isalpha(caractere)) {
        printf("%c é uma letra.\n", caractere);
    } else {
        printf("%c não é uma letra.\n", caractere);
    }

    return 0;
}
