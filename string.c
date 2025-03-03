#include "string.h"
#define NULL '\0'

void CopyString(char pcSource[], char pcDestination[])
{

    unsigned char ucCharacterIndex;

    for(ucCharacterIndex = 0 ; pcSource[ucCharacterIndex] != NULL ; ucCharacterIndex++)
    {
        pcDestination[ucCharacterIndex] = pcSource[ucCharacterIndex];
    }
    pcDestination[ucCharacterIndex] = pcSource[ucCharacterIndex];
}




enum CompResult eCompareString(char pcStr1[], char pcStr2[])
{

    unsigned char ucCharacterIndex;

    for(ucCharacterIndex = 0 ; pcStr1[ucCharacterIndex] != NULL || pcStr2[ucCharacterIndex] != NULL ; ucCharacterIndex++)
    {
        if( pcStr1[ucCharacterIndex] != pcStr2[ucCharacterIndex] )
        {
            return DIFFERENT;
        }
    }

    return EQUAL;
}



void AppendString (char pcSourceStr[], char pcDestinationStr[])
{

    unsigned char ucCharacterIndex ;

    for(ucCharacterIndex = 0 ; pcDestinationStr[ucCharacterIndex] ; ucCharacterIndex++){}
    CopyString(pcSourceStr, pcDestinationStr + ucCharacterIndex);
}



void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar)
{

    unsigned char ucCharacterIndex;

    for(ucCharacterIndex = 0 ; pcString[ucCharacterIndex] ; ucCharacterIndex++)
    {
        if(pcString[ucCharacterIndex] == cOldChar)
        {
            pcString[ucCharacterIndex] = cNewChar;
        }
    }
}
