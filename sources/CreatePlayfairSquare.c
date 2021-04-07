#include <stdio.h>
#include <string.h>

void leftShift(char string[26], int start)
{
    for (int i = start; i < strlen(string); i++)
    {
        string[i] = string[i + 1];
    }
}

void removeNoLettersCharacters(char key[32])
{
    int i = 0;
    do
    {
        if (!((key[i] > 64 && key[i] < 91) || (key[i] > 96 && key[i] < 123)))
        {
            leftShift(key, i);
        }
        else
        {
            i++;
        }
    } while (i < strlen(key));
}

void toUpperCase(char string[32])
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] >= 97 && string[i] <= 122)
        {
            string[i] -= 32;
        }
    }
}

void replaceJIntoI(char key[26])
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (key[i] == 74)
        {
            key[i] = key[i] - 1;
        }
    }
}

int stringHasLetter(char string[26], char letter, int position)
{
    int containsLetter = 0;
    for (int i = 0; i < position; i++)
    {
        if (string[i] == letter)
        {
            containsLetter = 1;
        }
    }
    return containsLetter;
}

void deleteDuplicatesLettersInKey(char key[26])
{
    int i = 0;
    do
    {
        if (stringHasLetter(key, key[i], i) != 0)
        {
            leftShift(key, i);
        }
        else
        {
            i++;
        }
    } while (key[i] != '\0');
}

void deleteUsedLettersInKey(char key[26], char letters[26])
{
    int i = 0;
    do
    {
        if (stringHasLetter(key, letters[i], strlen(key)) != 0)
        {
            leftShift(letters, i);
        }
        else
        {
            i++;
        }
    } while (letters[i] != '\0');
}

void createPlayfairSquare(char playfairSquare[5][5], char key[26])
{
    char letters[26] = {
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        'G',
        'H',
        'I',
        'K',
        'L',
        'M',
        'N',
        'O',
        'P',
        'Q',
        'R',
        'S',
        'T',
        'U',
        'V',
        'W',
        'X',
        'Y',
        'Z',
    };
    removeNoLettersCharacters(key);
    toUpperCase(key);
    replaceJIntoI(key);
    deleteDuplicatesLettersInKey(key);
    printf("Cle preparee : %s\n", key);
    deleteUsedLettersInKey(key, letters);
    strcat(key, letters);

    for (int i = 0; i < strlen(key); i++)
    {
        playfairSquare[i / 5][i % 5] = key[i];
    }
}

void printPlayfairSquare(const char playfairSquare[5][5])
{
    printf("carre :\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf(" %c ", playfairSquare[i][j]);
        }
        printf("\n");
    }
}