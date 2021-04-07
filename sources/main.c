#include <stdio.h>
#include <string.h>

#include "CreatePlayfairSquare.h"

int main(int argc, char const *argv[])
{
    char playfairSquare[5][5];
    char key[26];
    char message[128];
    printf("Cle depart : ");
    fgets(key, 26, stdin);
    createPlayfairSquare(playfairSquare, key);
    printPlayfairSquare(playfairSquare);
    printf("message en clair : ");
    fgets(message, 128, stdin);
    encodeMessage(playfairSquare, message);
    printMessage(message);
    decodeMessage(playfairSquare, message);
    printf("\nMessage decrypte : ");
    for (int i = 0; i < strlen(message); i += 2)
    {
        printf("%c%c ", message[i], message[i + 1]);
    }
}
