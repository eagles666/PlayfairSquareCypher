#include <stdio.h>
#include <string.h>

void appendLetter(char msg[64])
{
    char finalLetter[2];
    if (strlen(msg) % 2 != 0)
    {
        finalLetter[0] = msg[strlen(msg) - 1] != 'X' ? 'X' : 'Y';
        strcat(msg, finalLetter);
    }
}

void formatMessage(char message[64])
{
    for (int i = 0; i < strlen(message); i += 2)
    {
        if (message[i + 1] == message[i])
        {
            message[i + 1] = 'X';
        }
    }
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

void encodeMessage(char playfairSquare[5][5], char msg[64])
{
    removeNoLettersCharacters(msg);
    toUpperCase(msg);
    printf("Message purge : %s\n", msg);
    replaceJIntoI(msg);
    formatMessage(msg);
    appendLetter(msg);
    printf("Message prepare : %s\n", msg);

    for (int i = 0; i < strlen(msg); i += 2)
    {
        int positionFirstLetter = letterPosition(playfairSquare, msg[i]);
        int positionSecondLetter = letterPosition(playfairSquare, msg[i + 1]);
        if (positionFirstLetter / 5 == positionSecondLetter / 5)
        {
            msg[i] = positionFirstLetter % 5 != 4 ? playfairSquare[positionFirstLetter / 5][(positionFirstLetter % 5) + 1] : playfairSquare[positionFirstLetter / 5][0];
            msg[i + 1] = positionSecondLetter % 5 != 4 ? playfairSquare[positionSecondLetter / 5][(positionSecondLetter % 5) + 1] : playfairSquare[positionSecondLetter / 5][0];
        }

        else if (positionFirstLetter % 5 == positionSecondLetter % 5)
        {
            msg[i] = positionFirstLetter / 5 != 4 ? playfairSquare[(positionFirstLetter / 5) + 1][positionFirstLetter % 5] : playfairSquare[0][positionFirstLetter % 5];
            msg[i + 1] = positionSecondLetter / 5 != 4 ? playfairSquare[(positionSecondLetter / 5) + 1][positionSecondLetter % 5] : playfairSquare[0][positionSecondLetter % 5];
        }
        else
        {
            msg[i] = playfairSquare[positionFirstLetter / 5][positionSecondLetter % 5];
            msg[i + 1] = playfairSquare[positionSecondLetter / 5][positionFirstLetter % 5];
        }
    }
}

void printMessage(char message[64])
{
    printf("Message crypte : ");
    for (int i = 0; i < strlen(message); i += 2)
    {
        printf("%c%c ", message[i], message[i + 1]);
    }
}

// cle : radio londre
// msg : Les chants les plus desesperes sont les chants les plus beaux