#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

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
}
