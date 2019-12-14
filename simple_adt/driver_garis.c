#include <stdio.h>
#include "garis.h"

int main() {
  GARIS L,L2;
  BacaGARIS (&L);
  TulisGARIS(L);
  BacaGARIS(&L2);
  TulisGARIS(L2);
  printf("\n");
  printf("%.2f\n",PanjangGARIS(L));
  printf("%.2f",Gradien(L));
  GeserGARIS(&L,1,1);
  printf("HASIL GESER : ");
  TulisGARIS(L);
  if(IsTegakLurus(L,L2)){
      printf("Tegak lurus");
  };
   if (IsSejajar(L,L2)){
      printf("Sejajar");
  }
  return 0;
}