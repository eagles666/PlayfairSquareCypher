#include <stdio.h>
#include <string.h>

void encodeMessage(char playfairSquare[5][5], char message[32])
{
    if (strlen(message) % 2 != 0)
    {
        message[strlen(message) + 1] = 'X';
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
            i = i + 2;
        }
    } while (message[i + 1] != '\0');

    printf("%s\n", message);
}

int letterPosition(const char playfairSquare[5][5], char letter)
{
    int letterPosition;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (playfairSquare[i][j] == letter)
            {
                letterPosition = i * 5 + j;
            }
        }
    }

    return letterPosition;
}