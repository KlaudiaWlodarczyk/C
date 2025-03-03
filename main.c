#include "string.h"
#include "konwersje.h"
#include "dekodowanie.h"
#include <stdio.h>
#include <string.h>
#define NUL '\0'


extern struct Token asToken[];

void TestOf_CopyString(void)
{

	printf("CopyString\n\n ");

	printf("Test 1 - ");
	//taka sama dlugosc 
	char cAfterCopy1[] = "12345";
	CopyString("abcde", cAfterCopy1);
	if(eCompareString("abcde", cAfterCopy1) == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//wyraz kopiowany mniejszy od wyrazu w zmiennej docelowej
	char cAfterCopy2[] = "123456";
	CopyString("abc", cAfterCopy2);
	if(eCompareString("abc", cAfterCopy2) == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 3 - ");
	// pierwszy pusty wyraz kopiowany
	char cAfterCopy3[] = "fghij";
	CopyString("", cAfterCopy3);
	if(eCompareString("", cAfterCopy3) == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");
}
//----------------------------------------------------------
void TestOf_eCompareString(void) {

	printf("eCompareString\n\n ");

	printf("Test 1 - ");
	//takie same wyrazy o takiej samej dlugosci
	if(eCompareString("abcde", "abcde") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//rozne wyrazy o takiej samej dlugosci
	if(eCompareString("abcde", "fghij") == DIFFERENT) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 3 - ");
	///jeden wyraz pusty
	if(eCompareString("", "fghij") == DIFFERENT) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 4 - ");
	///oba wyrazy puste
	if(eCompareString("", "") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 5 - ");
	///drugi wyraz dluzszy
	if(eCompareString("abcde", "abcdef") == DIFFERENT) printf("OK\n\n\n"); else printf("Error\n\n\n");
}
//----------------------------------------------------------
void TestOf_AppendString(void) {

	printf("AppendString\n\n ");

	printf("Test 1 - ");
	//dowolne
	char cAppendingTest1[] = "fghij";
	AppendString("abcde", cAppendingTest1);
	if(eCompareString(cAppendingTest1, "fghijabcde") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//pierwszy wyraz pusty
	char cAppendingTest2[] = "fghij";
	AppendString("", cAppendingTest2);
	if (eCompareString(cAppendingTest2, "fghij") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 3 - ");
	//drugi wyraz pusty
	char cAppendingTest3[] = "";
	AppendString("abcde", cAppendingTest3);
	if(eCompareString(cAppendingTest3, "abcde") == EQUAL) printf("OK\n\n\n"); else printf("Error\n\n\n");
}
//----------------------------------------------------------
void TestOf_ReplaceCharactersInString(void) {

	printf("ReplaceCharactersInString\n\n ");

	printf("Test 1 - ");
	//znaki alfanumeryczne
	char cOryginal1[] = "Tekst do zamiany znaku";
	ReplaceCharactersInString(cOryginal1, 'a', 'A');
	if(eCompareString(cOryginal1, "Tekst do zAmiAny znAku") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//spacja na NULL
	char cOryginal2[] = "Tekst do zamiany znaku";
	ReplaceCharactersInString(cOryginal2, ' ', '\0');
	if (eCompareString(cOryginal2, "Tekst\0do\0zamiany\0znaku") == EQUAL) printf("OK\n\n\n"); else printf("Error\n\n\n");
}
//----------------------------------------------------------
void TestOf_UIntToHexStr(void) {

	printf("UIntToHexStr\n\n ");

	printf("Test 1 - ");
	//liczby 10 15 na litery w hex
	char cAfterConverion[7];
	UIntToHexStr(0X09AF, cAfterConverion);
	if(eCompareString(cAfterConverion, "0X09AF") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//zera po x w stringu
	UIntToHexStr(0X34, cAfterConverion);
	if (eCompareString(cAfterConverion, "0x0034") == EQUAL) printf("OK\n\n\n"); else printf("Error\n\n\n");
}
//----------------------------------------------------------
void TestOf_eHexStringToUInt() {

	enum Result iReturnResult;
	unsigned int uiReturnValue;

	printf("eHexStringToUInt\n\n ");

	printf("Test 1 - ");
	//krance przedzialow
	iReturnResult = eHexStringToUInt("0X09AF", &uiReturnValue);
	if (iReturnResult == OK) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//za krotki lancuch znakowy
	iReturnResult = eHexStringToUInt("0X", &uiReturnValue);
	if (iReturnResult == ERROR) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 3 - ");
	//za dlugi lancuch znakowy
	iReturnResult = eHexStringToUInt("0XFFDC2", &uiReturnValue);
	if (iReturnResult == ERROR) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 4 - ");
	//poczatek lancucha znakowego rozny od 0X
	iReturnResult = eHexStringToUInt("34AC", &uiReturnValue);
	if (iReturnResult == ERROR) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 5 - ");
	//mniej znakow
	iReturnResult = eHexStringToUInt("0X034", &uiReturnValue);
	if (iReturnResult == OK) printf("OK\n\n\n"); else printf("Error\n\n\n");
}
//----------------------------------------------------------
void TestOf_AppendUIntToString() {

	printf("AppendUIntToString\n\n ");

	printf("Test 1 - ");
	//niepusty string, dopisywanie od NULLa
	char cOryginal1[] = "Jakis tekst";
	AppendUIntToString(0X1234,cOryginal1);
	if(eCompareString(cOryginal1,"Jakis tekst0X1234") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//pusty string
	char cOryginal2[] = "";
	AppendUIntToString(0X1234,cOryginal2);
	if(eCompareString(cOryginal2,"0X1234") == EQUAL) printf("OK\n\n\n"); else printf("Error\n\n\n");
}
//----------------------------------------------------------
void TestOf_ucFindTokensInString() {

	unsigned char ucTokenNumber;

	printf("ucFindTokensInString\n\n ");

	printf("Test 1 - ");
	//maksymalna liczba tokenow
	ucTokenNumber = ucFindTokensInString("0X3343 ABDCDEFGH reset");
	if(ucTokenNumber == 3) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//same delimitery
	ucTokenNumber = ucFindTokensInString("    ");
	if(ucTokenNumber == 0) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 3 - ");
	//delimitery na poczatku stringu, mniej tokenow niz maks
	ucTokenNumber = ucFindTokensInString("   0X3343 ABDCDEFGH ");
	if(ucTokenNumber == 2) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 4 - ");
	//kilka delimiterow pomiedzy tokenami
	ucTokenNumber = ucFindTokensInString("0X3343   ABDCDEFGH      reset");
	if(ucTokenNumber == 3) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 5 - ");
	//za duzo tokenow, (zwraca 3 i ustawia wskazniki na pierwsze 3)
	char pcTestString[] = "0X3343 ABDC DEFGH reset";
	ucTokenNumber = ucFindTokensInString(pcTestString);
	if((ucTokenNumber == 3) && (&pcTestString[0] == asToken[0].uValue.pcString)
			&& (&pcTestString[7] == asToken[1].uValue.pcString)
			&& (&pcTestString[12] == asToken[2].uValue.pcString)) printf("OK\n\n\n"); else printf("Error\n\n\n");
}
//----------------------------------------------------------
void TestOf_eStringToKeyword() {

	enum KeywordCode eTokenCode;

	printf("eStringToKeyword\n\n ");

	printf("Test 1 - ");
	//slowo kluczowe
	if (eStringToKeyword("reset", &eTokenCode) == OK) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	//brak slowa kluczowego
	if (eStringToKeyword("tekst", &eTokenCode) == ERROR) printf("OK\n\n\n"); else printf("Error\n\n\n");
}
//----------------------------------------------------------
void TestOf_DecodeTokens() {

	unsigned char ucTokenNumber;

	char pcSource1[]="0X3343 ABDCDEFGH reset";

	printf("DecodeTokens\n\n ");

	printf("Test 1 - ");
	//liczba i zapis jej, string i ustawienie wskaznika, keyword i zapis kodu
	ucTokenNumber = ucFindTokensInString(pcSource1);
	ReplaceCharactersInString(pcSource1,' ',NUL);
	DecodeTokens();
	if ((asToken[0].eType == NUMBER) && (asToken[0].uValue.uiNumber == 0X3343) &&
			(asToken[1].eType == STRING) && (&pcSource1[7] == asToken[1].uValue.pcString) &&
			(asToken[2].eType == KEYWORD) && (asToken[2].uValue.eKeyword == RST)) printf("OK\n\n\n"); else printf("Error\n\n\n");
}
//----------------------------------------------------------
void TestOf_DecodeMsg() {

	char pcToDecode[]="0X3343 ABDCDEFGH reset";

	printf("DecodeMsg\n\n ");

	printf("Test 1 - ");
	//liczba, string, keyword
	DecodeMsg(pcToDecode);
	if ((asToken[0].eType == NUMBER) && (asToken[0].uValue.uiNumber == 0X3343) &&
			(asToken[1].eType == STRING) && (&pcToDecode[7] == asToken[1].uValue.pcString) &&
			(asToken[2].eType == KEYWORD) && (asToken[2].uValue.eKeyword == RST)) printf("OK\n\n\n"); else printf("Error\n\n\n");
}
//----------------------------------------------------------
int main(void) {

	printf("TESTY FUNKCJI - LANCUCHY ZNAKOWE - OPERACJE PROSTE\n\n\n");

	TestOf_CopyString();
	TestOf_eCompareString();
	TestOf_AppendString();
	TestOf_ReplaceCharactersInString();

	printf("TESTY FUNKCJI - LANCUCHY ZNAKOWE - KONWERSJE\n\n\n");

	TestOf_UIntToHexStr();
	TestOf_eHexStringToUInt();
	TestOf_AppendUIntToString();

	printf("TESTY FUNKCJI - DEKODOWANIE KOMUNIKATOW\n\n\n");

	TestOf_ucFindTokensInString();
	TestOf_eStringToKeyword();
	TestOf_DecodeTokens();
	TestOf_DecodeMsg();
}
