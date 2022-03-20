#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void prtList(EP first){
    for(; first; first = first->next){
        printf("%c", first->c);
    }
    printf("\n");
}

EP newElement(char c){
    EP p = malloc( sizeof(ELEMENT) );
    if(p){
        p->c = c; p->next = 0;
    }
    return p;
}

void insertChar(char c, EP ptr){
    EP p = newElement(c);
    if(p){
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = p;
    }
}