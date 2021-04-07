void decodeMessage(char playfairSquare[5][5], char msg[64])
{
    for (int i = 0; i < strlen(msg); i += 2)
    {
        int positionFirstLetter = letterPosition(playfairSquare, msg[i]);
        int positionSecondLetter = letterPosition(playfairSquare, msg[i + 1]);
        if (positionFirstLetter / 5 == positionSecondLetter / 5)
        {
            msg[i] = positionFirstLetter % 5 > 0 ? playfairSquare[positionFirstLetter / 5][(positionFirstLetter % 5) - 1] : playfairSquare[positionFirstLetter / 5][4];
            msg[i + 1] = positionSecondLetter % 5 > 0 ? playfairSquare[positionSecondLetter / 5][(positionSecondLetter % 5) - 1] : playfairSquare[positionSecondLetter / 5][4];
        }

        else if (positionFirstLetter % 5 == positionSecondLetter % 5)
        {
            msg[i] = positionFirstLetter / 5 > 0 ? playfairSquare[(positionFirstLetter / 5) - 1][positionFirstLetter % 5] : playfairSquare[4][positionFirstLetter % 5];
            msg[i + 1] = positionSecondLetter / 5 > 0 ? playfairSquare[(positionSecondLetter / 5) - 1][positionSecondLetter % 5] : playfairSquare[4][positionSecondLetter % 5];
        }
        else
        {
            msg[i] = playfairSquare[positionFirstLetter / 5][positionSecondLetter % 5];
            msg[i + 1] = playfairSquare[positionSecondLetter / 5][positionFirstLetter % 5];
        }
    }
}
