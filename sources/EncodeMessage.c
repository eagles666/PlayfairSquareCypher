#include <stdio.h>
#include <string.h>

void encodeMessage(char playfairSquare[5][5], char message[32])
{
    char X[2] = "x";
    if (strlen(message) % 2 != 0)
    {
        strcat(message, X);
    }

    int i = 0;
    do
    {
        if (message[i] == message[i + 1])
        {
            message[i + 1] = 'X';
        }
        else
        {
        }
    } while (message[i + 1] != '\0');

    printf("%s", message);
}

int inSameRow(char playfairSquare[5][5], int row, char firstLetter, char secondLetter)
{
    int hasFirstLetter = 1, hasSecondLetter = 1;
    for (int column = 0; column > 5; column++)
    {
        if (playfairSquare[column][row] == firstLetter)
        {
            hasFirstLetter = 0;
        }
        if (playfairSquare[column][row] == secondLetter)
        {
            hasSecondLetter = 0;
        }
    }
    return hasFirstLetter == 0 && hasSecondLetter == 0 ? 0 : 1;
}