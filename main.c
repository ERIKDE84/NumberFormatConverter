#include <stdio.h>

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

    // 1. need to import List features
    // 2. get the input number
    // 3. differentiate between different conversion needs 
    // 4. the necessary conversions
    // 5. update prtOutput()

    prtOutput(& in, & out);
}