/* Ethan Richards

This project expresses an understanding of Bitwise Operators, formatted input with
key-phrases, formatted output in hex and binary, and storage types.

The codeword will be built using a (21, 16) Hamming code.  That is, this code takes 16 bits (two bytes) of information
and adds in five more parity bits to give a 21-bit codeword.  When transmitted, this code word will allow a user to
determine if the information transmitted arrived correctly—or not—as long as no more than one bit gets corrupted.
Thus it is called a single bit-error correcting code. The non-parity (information) bits will simply be the values they
were in the original 16 bits, only shifted to their new position.

ASSUMPTIONS: The user will type in EXIT as asked. The user will only input two
characters, or the first two characters will get taken when wanting to test
two characters.
*/

//libraries
#include <stdio.h>
#include <string.h>

//prototypes
int shiftBitsIntoCodeWord(int original);
int bitOneCheck(int codeCheck);
int bitTwoCheck(int codeCheck);
int bitFourCheck(int codeCheck);
int bitEightCheck(int codeCheck);
int bitSixteenCheck(int codeCheck);
void printingOutputs(int original, int finalWord);
int convertToBinary(int originalNumber);

//main
int main(void){
    char keyphrase[5];
    int userInput;
    int codeWord;

    strcpy(keyphrase, "BLUE");

//Taking Inputs and making sure it's not exit before continuing
    while(strcmp(keyphrase, "EXIT") != 0){
        printf("Input two ASCII characters or EXIT to leave: ");
        scanf("%s", keyphrase);
        if(strcmp(keyphrase, "EXIT") == 0){
            printf("Thank you, Goodbye.\n");
            return 0;
        }

//Put together the bits from the original into the userInput
//The second ascii character is the more important bit
        userInput = keyphrase[1];
        userInput <<= 8;
        userInput |= keyphrase[0];

//Shift bits into place
        codeWord = shiftBitsIntoCodeWord(userInput);

//It's Parity Time
        codeWord |= bitOneCheck(codeWord);
        codeWord |= bitTwoCheck(codeWord);
        codeWord |= bitFourCheck(codeWord);
        codeWord |= bitEightCheck(codeWord);
        codeWord |= bitSixteenCheck(codeWord);

//Printing the OG userInput and the codeWord
        printingOutputs(userInput, codeWord);
    }

    return 0;
}

/*	FUNCTION HEADER
    DESCRIPTION: This function shifts the original user input into new positions in a 32 bit integer for use
	of parity bits in the code word.
    INPUT: This function takes in the user input of 2 ascii characters
    OUTPUT: The output of this function is the user input ascii inputs parsed for hamming code parity bits to be added
*/
int shiftBitsIntoCodeWord(int original){
    int storageTemp;
    int storageCodeWord = 0;

//shifts bits 12-16
    storageTemp = original & 0xF800;
    storageTemp <<= 5;
    storageCodeWord |= storageTemp;

//shifts bits 5-11
    storageTemp = original & 0x7F0;
    storageTemp <<= 4;
    storageCodeWord |= storageTemp;

//shifts bits 2-4
    storageTemp = original & 0xE;
    storageTemp <<= 3;
    storageCodeWord |= storageTemp;

//shifts bit 1
    storageTemp = original & 0x1;
    storageTemp <<= 2;
    storageCodeWord |= storageTemp;

    return storageCodeWord;
}

/*	FUNCTION HEADER
	DESCRIPTION: This function implements the parity bit, bit 1 based ont the hamming parity
    INPUT: The parsed user input.
    OUTPUT: A singular bit to be used for manipulation of the code word parity bit error for a (21, 16) Hamming Code.
*/
int bitOneCheck(int codeCheck){
    int checker = 0;
//adds parity bit 1 based off of 3,5,7,9,11,13,15,17,19,21
    checker += ((codeCheck>>2)%2)+((codeCheck>>4)%2)+((codeCheck>>6)%2);
    checker += ((codeCheck>>8)%2)+((codeCheck>>10)%2)+((codeCheck>>12)%2);
    checker += ((codeCheck>>14)%2)+((codeCheck>>16)%2)+((codeCheck>>18)%2);
    checker += ((codeCheck>>20)%2);

    if(checker%2 == 0)
        return 0x0;
    else
        return 0x1;
}

/*	FUNCTION HEADER
	DESCRIPTION: This function implements the parity bit, bit 2 based ont the hamming parity
    INPUT: The parsed user input.
    OUTPUT: A singular bit to be used for manipulation of the code word parity bit error for a (21, 16) Hamming Code.
*/
int bitTwoCheck(int codeCheck){
    int checker = 0;
//adds parity bit 2 based off of 3,6,7,10,11,14,15,18,19
    checker += ((codeCheck>>2)%2)+((codeCheck>>5)%2)+((codeCheck>>6)%2);
    checker += ((codeCheck>>9)%2)+((codeCheck>>10)%2)+((codeCheck>>13)%2);
    checker += ((codeCheck>>14)%2)+((codeCheck>>17)%2)+((codeCheck>>18)%2);

    if(checker%2 == 0)
        return 0x0;
    else
        return 0x2;
}

/*	FUNCTION HEADER
	DESCRIPTION: This function implements the parity bit, bit 4 based ont the hamming parity
    INPUT: The parsed user input.
    OUTPUT: A singular bit to be used for manipulation of the code word parity bit error for a (21, 16) Hamming Code.
*/
int bitFourCheck(int codeCheck){
    int checker = 0;
//adds parity bit 4 based off of 5,6,7,12,13,14,15,20,21
    checker += ((codeCheck>>4)%2)+((codeCheck>>5)%2);
    checker += ((codeCheck>>6)%2)+((codeCheck>>11)%2)+((codeCheck>>12)%2);
    checker += ((codeCheck>>13)%2)+((codeCheck>>14)%2)+((codeCheck>>19)%2);
    checker += ((codeCheck>>20)%2);

    if(checker%2 == 0)
        return 0x0;
    else
        return 0x8;

}

/*	FUNCTION HEADER
	DESCRIPTION: This function implements the parity bit, bit 8 based ont the hamming parity
    INPUT: The parsed user input.
    OUTPUT: A singular bit to be used for manipulation of the code word parity bit error for a (21, 16) Hamming Code.
*/
int bitEightCheck(int codeCheck){
    int checker = 0;
//adds parity bit 8 based off of 8,9,10,11,12,13,14,15
    checker += ((codeCheck>>7)%2)+((codeCheck>>8)%2)+((codeCheck>>9)%2);
    checker += ((codeCheck>>10)%2)+((codeCheck>>11)%2)+((codeCheck>>12)%2);
    checker += ((codeCheck>>13)%2)+((codeCheck>>14)%2);

    if(checker%2 == 0)
        return 0x0;
    else
        return 0x80;

}

/*	FUNCTION HEADER
	DESCRIPTION: This function implements the parity bit, bit 16 based ont the hamming parity
    INPUT: The parsed user input.
    OUTPUT: A singular bit to be used for manipulation of the code word parity bit error for a (21, 16) Hamming Code.
*/
int bitSixteenCheck(int codeCheck){
    int checker = 0;
//adds parity bit 16 based off of 16,17,18,19,20,21
    checker += ((codeCheck>>15)%2)+((codeCheck>>16)%2)+((codeCheck>>17)%2);
    checker += ((codeCheck>>18)%2)+((codeCheck>>19)%2)+((codeCheck>>20)%2);

    if(checker%2 == 0)
        return 0x0;
    else
        return 0x8000;;

}

/*	FUNCTION HEADER
    DESCRIPTION: The objective of this function is to print out the original characters
	in hex and binary, and the code word in hex and binary.
    INPUT: Original Word and Code Word as integers for printing.
    OUTPUT: None. Function just prints.
*/
void printingOutputs(int original, int finalWord){
    //NOTE: 1 AND 2 TIED TO ORIGINAL, 3 - 5 TIED TO FINAL WORD
    //integers for parsing the characters by byte
    int storageOne, storageTwo, storageThree, storageFour, storageFive;
    //integers for creating pseudo-binary representation of each byte
    int OneBin, TwoBin, ThreeBin, FourBin, FiveBin;

//gets the original and final words into bytes
    storageOne = 0xFF & original;
    storageTwo = 0xFF00 & original;
    storageTwo >>= 8;
    storageThree = 0xFF & finalWord;
    storageFour = 0xFF00 & finalWord;
    storageFour >>= 8;
    storageFive = 0x1F0000 & finalWord;
    storageFive >>=16;

//retrieves the binary string that makes up each portion
    OneBin = convertToBinary(storageOne);
    TwoBin = convertToBinary(storageTwo);
    ThreeBin = convertToBinary(storageThree);
    FourBin = convertToBinary(storageFour);
    FiveBin = convertToBinary(storageFive);

//hex prints done differently for original and finalWord to show two different methods of printing the values
//prints original
    printf("                  %8c %8c\n",storageTwo, storageOne);
    printf("0x    00       00 %8x %8x\n",storageTwo, storageOne);
    printf("-------- -------- %08i %08i\n\n\n\n",TwoBin, OneBin);

//prints final in hex and binary
    printf("0x 0   0 %4x%4x ", (storageFive >> 4), storageFive);
    printf("%4x%4x ", (storageFour >> 4), (storageFour & 0xF));
    printf("%4x%4x\n", (storageThree >> 4), (storageThree & 0xF));
    printf("-------- ---%05i %08i %08i\n", FiveBin, FourBin, ThreeBin);

    return;
}

/*	FUNCTION HEADER
	DESCRIPTION: The goal of this function is to turn the decimal number of the
	received int, and convert it into an integer that is pseudo-binary.
	The goal of this is to create a printable integer that represents
	the decimal number in binary.
    INPUT: an integer to be represented in binary
    OUTPUT: An integer that is represented by pseudo-binary
*/
int convertToBinary(int originalNumber){
    int i,j,k, number;
    number = 0;

    //Collects the intended bit value and shifts to the location needed, then adds that to 'number' that is output
    //as the pseudo-binary
    for(j=0; originalNumber != 0; j++){
        i = originalNumber%2;
        for(k = 0; k<j; k++){
            i *= 10;
        }
        number += i;
        originalNumber /= 2;
    }

    return number;
}
