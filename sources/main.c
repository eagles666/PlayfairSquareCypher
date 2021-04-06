#include <stdio.h>
#include <string.h>

#include "CreatePlayfairSquare.h"
#include "Encode.h"

int main(int argc, char const *argv[])
{
    // char key[26] = "EXEMPLEPLAYFAIR";
    char playfairSquare[5][5];
    char msg[32] = "CACHELORDANSLASOUCHEDELARBRE";
    char key[26];
    printf("Saisir clé : ");
    fgets(key, 26, stdin);
    printf("%s\n", key);
    removeSpaces(key);
    printf("%s", key);

    //createPlayfairSquare(playfairSquare, key);
    //printPlayfairSquare(playfairSquare);
    // encodeMessage(playfairSquare, msg);
}
