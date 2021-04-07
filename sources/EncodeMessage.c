#include <stdio.h>
#include <string.h>

void formatMessage(char message[32])
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

    // printf("%s\n", message);
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

int encodeMessage(char playfairSquare[5][5], char msg[64])
{
    removeNoLettersCharacters(msg);
    toUpperCase(msg);
    replaceJIntoI(msg);
    formatMessage(msg);
    printf("%s\n", msg);

    for (int i = 0; i < strlen(msg); i += 2)
    {
        printf("%c%c\n", msg[i], msg[i + 1]);
        int positionFirstLetter = letterPosition(playfairSquare, msg[i]);
        int positionSecondLetter = letterPosition(playfairSquare, msg[i + 1]);
        printf("position lettre 1 : %d\nposition lettre 2 : %d\n", positionFirstLetter, positionSecondLetter);

        if (positionFirstLetter / 5 == positionSecondLetter / 5)
        {
            msg[i] = positionFirstLetter % 5 != 4 ? playfairSquare[positionFirstLetter / 5][(positionFirstLetter % 5) + 1] : playfairSquare[positionFirstLetter / 5][0];
            msg[i + 1] = positionSecondLetter % 5 != 4 ? playfairSquare[positionSecondLetter / 5][(positionSecondLetter % 5) + 1] : playfairSquare[positionSecondLetter / 5][0];
        }

        else if (positionFirstLetter % 5 == positionSecondLetter % 5)
        {
            printf("%c -> %c\n", msg[i], positionFirstLetter / 5 != 4 ? playfairSquare[(positionFirstLetter / 5) + 1][positionFirstLetter % 5] : playfairSquare[0][positionFirstLetter % 5]);
            msg[i] = positionFirstLetter / 5 != 4 ? playfairSquare[(positionFirstLetter / 5) + 1][positionFirstLetter % 5] : playfairSquare[0][positionFirstLetter % 5];
            printf("%c -> %c\n", msg[i + 1], positionSecondLetter / 5 != 4 ? playfairSquare[(positionSecondLetter / 5) + 1][positionSecondLetter % 5] : playfairSquare[0][positionSecondLetter % 5]);
            msg[i + 1] = positionSecondLetter / 5 != 4 ? playfairSquare[(positionSecondLetter / 5) + 1][positionSecondLetter % 5] : playfairSquare[0][positionSecondLetter % 5];
        }
        /*
        else
        {
            printf("%c et %c ne sont pas sur la meme ligne ni la meme colonne.\n", msg[i], msg[i + 1]);
        }
        */
    }
}