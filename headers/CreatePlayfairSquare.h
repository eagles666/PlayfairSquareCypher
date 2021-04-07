#ifndef PLAYFAIRCIPHER_CRYPT_H
#define PLAYFAIRCIPHER_CRYPT_H

void leftShift(char[26], int);
void removeNoLettersCharacters(char[26]);
void toUpperCase(char[32]);
void replaceJIntoI(char[26]);
int stringHasLetter(char[26], char, int);
void deleteDuplicatesLettersInKey(char[26]);
void deleteUsedLettersInKey(char[26], char[26]);
void createPlayfairSquare(char[5][5], char[26]);
void printPlayfairSquare(const char[5][5]);

#endif // PLAYFAIRCIPHER_CRYPT_H