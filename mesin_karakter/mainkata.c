#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include "boolean.h"

int  main (){
   STARTKATA();
   while (!EndKata){
       for(int i=1;i<=CKata.Length;i++){
           printf("%c",CKata.TabKata[i]);
       }
       printf("\n");
       ADVKATA();
   }
    return 0;
}