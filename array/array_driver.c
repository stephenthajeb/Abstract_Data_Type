#include <stdio.h>
#include "array.h"

int main() {
    TabInt T1;
    TabInt T2;
    int X = 6;
    BacaIsi(&T1);
    BacaIsiTab(&T1); 
    BacaIsiTab(&T2);
    
    // /*
    // if (IsEQ(T1, T2) == true) {
    //     printf("True\n");
    // } else {
    //     printf("False\n");
    // }
    // */

//Masih Salah
    // if (IsLess(T1, T2) == true) {
    //     printf("True\n");
    // } else {
    //     printf("False\n");
    // }
    
    printf("%d\n", Search2(T1, 3));

    if (SearchSentinel(T1, 3) == true) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    CopyTab(T1, &T2);
    TulisIsi(InverseTab(T2));

    if (IsSimetris(T1)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
//     InsSortAsc(&T1);
//     TulisIsiTab(T1); printf("\n");
//     AddAsLastEl(&T1, 5);
//     TulisIsiTab(T1); printf("\n");
//     AddEli(&T1, 6, 2);
//     TulisIsiTab(T1); printf("\n");
//     DelLastEl(&T1, &X);
//     DelEli(&T1, 2, &X); 
//     TulisIsiTab(T1); printf("\n");

//     // MASIH ERROR AddElUnik(&T1, X);
//     printf("%d", SearchUrut(T1, 6)); printf("\n");
//     printf("%d", MaxUrut(T1)); printf("\n");
//     printf("%d", MinUrut(T1)); printf("\n");
//     Add1Urut(&T1, 4);
//     TulisIsiTab(T1); printf("\n");
//     Del1Urut(&T1, 5);
//     TulisIsiTab(T1); printf("\n");
 }