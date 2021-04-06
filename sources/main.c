#include <stdio.h>
#include <string.h>

#include "CreatePlayfairSquare.h"

int main(int argc, char const *argv[])
{
    char playfairSquare[5][5];
    char key[26];

    printf("Saisir clé : ");
    fgets(key, 26, stdin);
    removeNoLettersCharacters(key);
    printf("%s\n", key);
    toUpperCase(key);
    printf("%s\n", key);
    createPlayfairSquare(playfairSquare, key);
    printPlayfairSquare(playfairSquare);
}
