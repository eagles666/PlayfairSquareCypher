#include <stdio.h>
#include <string.h>

#include "CreatePlayfairSquare.h"

int main(int argc, char const *argv[])
{
    char playfairSquare[5][5];
    char key[26];

    printf("Cle depart : ");
    fgets(key, 26, stdin);
    createPlayfairSquare(playfairSquare, key);
    printPlayfairSquare(playfairSquare);
}
