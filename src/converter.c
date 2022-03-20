#include "converter.h"
#include "linkedList.h"
#include <stdio.h>
#include <math.h>

int charToValue(char c){
    switch (c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'a': 
    case 'A': return 10;
    case 'b':
    case 'B': return 11;
    case 'c':
    case 'C': return 12;
    case 'd':
    case 'D': return 13;
    case 'e':
    case 'E': return 14;
    case 'f':
    case 'F': return 15;
    default: return -1;
    }
}

char valueToChar(int i){
    switch (i){
    case 0: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
    case 13: return 'D';
    case 14: return 'E';
    case 15: return 'F';
    default: return 'S';
    }
}

void reverseCopy(EP dest, EP src){
    if(src->next){
        reverseCopy(dest, src->next);
    }
    insertChar(src->c, dest);
}

long toDecimal(EP inNum, double inpBase, double *exp){
    long sum = 0, i;
    if(inNum->next){
        sum += toDecimal(inNum->next, inpBase, exp);
    }
    i = charToValue(inNum->c);
    sum += (i * pow(inpBase, *exp));
    *exp += 1;
    return sum;
}

EP toAny(long sum, double outBase){
    long f = 1;
    int base = outBase;
    EP p = newElement(' '), k = newElement(' ');

    while(f != 0){
        insertChar(valueToChar(sum % base), p);
        f = sum /= base;
    }
    reverseCopy(k, p);
    return k;
}