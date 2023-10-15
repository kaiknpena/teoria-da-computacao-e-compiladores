#include <stdio.h>
#include <ctype.h>

int main() {
    char caractere = '3';

    if (isalnum(caractere)) {
        printf("%c é uma letra ou um dígito.\n", caractere);
    } else {
        printf("%c não é uma letra ou um dígito.\n", caractere);
    }

    return 0;
}
