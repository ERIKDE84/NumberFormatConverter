#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct _element {
    int i;
    struct _element *next;
}ELEMENT, *EP;

void prt_bin(EP first){
    if(first->next->next){
        prt_bin(first->next);
    }
    printf("%d", first->i);
}

EP newElement(int i){
    EP p = malloc( sizeof(ELEMENT) );
    if(p){
        p->i = i; p->next = 0;
    }
    return p;
}

void insertNum(int i, EP *ptr){
    EP p = newElement(i);
    if(p){
        while((*ptr)->next){
            ptr = & (*ptr)->next;
        }
        (*ptr)->i = p->i;
        (*ptr)->next = p;
    }
}

int isdigit_long(char *str, long *np){ 
    *np = strtol(str, 0, 10);
    for(int i = 0; str[i]; i++){
        if( !isdigit(str[i]) ){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv){
    long num, f=1;
    EP first = newElement(0);

    if(argc != 2){
        printf("Input quantity should be 1!\n");
        return 0;
    }else if( isdigit_long(argv[1], & num) ){
        printf("Input --> Decimal: %ld\n", num);   
        while( f != 0 ){
            insertNum(num % 2, & first);
            f = num /= 2;
        }
    } else {
        printf("Input is not an integer!\n");
    }

    printf("Output --> Binary: ");
    prt_bin(first);
    printf("\n");
}
