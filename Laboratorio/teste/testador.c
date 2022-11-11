#include <stdio.h>

int main() {
    // 9223372036854776000 2^63
    unsigned long long int dobro = 0;//18446744073709551615llu;
    int inteiro = 0;
    dobro = ((unsigned long long int)(1<<31)<<32);
    if(dobro & ((unsigned long long int)1<<63)){
        inteiro = 64;
    }
    // inteiro =  (1<<30);
    printf("\n long long int: %llu",dobro);
    printf("\n inteiro:       %u",inteiro);

    return 0;
}