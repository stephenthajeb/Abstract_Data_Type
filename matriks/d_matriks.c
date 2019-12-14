#include <stdio.h>
#include "matriks.h"
#include <stdlib.h>


int main () {
    MATRIKS M1,M2;
    BacaMATRIKS (&M1,1,2);
    TulisMATRIKS (M1);
    BacaMATRIKS (&M2,2,2);
    TulisMATRIKS (M2);
    printf("KaliMatriks");
    TulisMATRIKS(KaliMATRIKS(M1,M2));
    printf("\n");
    
}