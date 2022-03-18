#include <stdio.h>
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
    printf("\n");
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
            return "kein case erfuellt";
    }
}

void prtOutput(int *in_ptr, int *out_ptr){
    printf("Input - %s: \n", matchToFormat(*in_ptr));
    printf("Output - %s: \n\n", matchToFormat(*out_ptr));
}

int main(int argc, char **argv){
    int in = 0, out = 0;
    getFormats(& in, & out);

    

    // 2. get the input number --> maybe import list?
    // 3. differentiate between different conversion needs 
    // 4. the necessary conversions
    // 5. update prtOutput()

    prtOutput(& in, & out);
}