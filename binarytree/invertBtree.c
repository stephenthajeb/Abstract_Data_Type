#include "bintree.h"
#include "listrek.h"
#include <stdio.h>

// Stephen Thajeb 13518150
// invertBtree.c
// 16-11-2019

void InvertBtree(BinTree *P){
    BinTree temp;
  
    if (IsTreeEmpty(*P)){

    }else {
      temp = Left(*P);
      Left(*P) = Right(*P); 
      Right(*P) = temp;
      InvertBtree(&Left(*P));
      InvertBtree(&Right(*P));
    }
  
}
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */