#include <stdio.h>
#include <stdlib.h>
#include "src/linkedList.h"

void getFormats(int *in_ptr, int *out_ptr){
    printf("\n1: decimal\n"
           "2: binary\n"
           "3: octal\n"
           "4: hexadecimal\n\n");    
    
    while (1){
        printf("Choose an input format --> ");
        scanf("%d", in_ptr);

        if(*in_ptr > 0 && *in_ptr < 5){
            break;
        } else {
            printf("Invalid input - please try again!\n");
        }
    }

    while (1){
        printf("Choose an output format --> ");
        scanf("%d", out_ptr);

        if(*out_ptr > 0 && *out_ptr < 5){
            break;
        } else {
            printf("Invalid input - please try again!\n");
        }
    }
}

char *matchToFormat(int i){
    switch (i){
        case 1:
            return "Decimal";
        case 2:
            return "Binary";
        case 3:
            return "Octal";
        case 4:
            return "Hexadecimal";
        default:
            return "No format identified";
    }
}

void prtOutput(int *in_ptr, int *out_ptr, EP in, EP out){
    printf("\nInput - %s: ", matchToFormat(*in_ptr));
    prtList(in->next);
    printf("Output - %s: ", matchToFormat(*out_ptr));
    prtList(out);
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
    int in_Format = 0, out_Format = 0;
    EP in_Number, out_Number = newElement('?');

    getFormats(& in_Format, & out_Format);
    in_Number = getNumber(); 

    //  differentiate between different conversion needs 
    //  compute conversions

    prtOutput(& in_Format, & out_Format, in_Number, out_Number);
}