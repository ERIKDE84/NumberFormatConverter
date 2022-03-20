#include "src/linkedList.h"
#include "src/converter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getFormat(double *base, char *str){
    while (1){
        scanf("%lf", base);
        if(*base > 0 && *base < 5){
            break;
        } else {
            printf("Invalid input - please try again!\n--> ");
        }
    }

    int i = *base;
    switch (i){
        case 1:
            *base = 10.0; 
            strcpy(str, "Decimal"); 
            break;
        case 2:
            *base = 2.0; 
            strcpy(str, "Binary"); 
            break;
        case 3:
            *base = 8.0; 
            strcpy(str, "Octal");
            break;
        case 4:
            *base = 16.0; 
            strcpy(str, "Hexadecimal"); 
            break;
    }
}

void prtOutput(char *inStr, char *outStr, EP in, EP out){
    printf("\nInput - %s: ", inStr);
    prtList(in->next);
    printf("Output - %s: ", outStr);
    prtList(out->next);
    printf("\n\n");
}

EP getNumber(){
    char c; 
    EP p = newElement('!');
    
    printf("Enter your number: ");
    c = getchar();
    while( (c = getchar()) != '\n' && c != EOF && 
           ( (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') )){
            insertChar(c, p);
    }
    return p;
}

int main(int argc, char **argv){
    double inpBase = 0, outBase = 0, exp = 0;
    char inStr[12], outStr[12];
    EP inpNum, outNum;
    long sum = 0;

    printf("\n1: decimal\n" "2: binary\n" "3: octal\n" "4: hexadecimal\n\n");   //Get Inputs

    printf("Choose an input format --> ");
    getFormat(& inpBase, inStr);

    printf("Choose an output format --> ");
    getFormat(& outBase, outStr);

    inpNum = getNumber();

    if(inpBase == outBase){
        prtOutput(inStr, outStr, inpNum, inpNum);
    } else {
        sum = toDecimal(inpNum->next, inpBase, & exp);  //convert to Decimal 
        outNum = toAny(sum, outBase);                   //convert to desired format
        prtOutput(inStr, outStr, inpNum, outNum);
    }
}