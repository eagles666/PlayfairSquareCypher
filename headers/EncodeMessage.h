#ifndef PLAYFAIRCIPHER_ENCODE_H
#define PLAYFAIRCIPHER_ENCODE_H

void formatMessage(char[32]);
int letterPosition(char[5][5], char);
int encodeMessage(char[5][5], char[32]);

#endif // PLAYFAIRCIPHER_ENCODE_H