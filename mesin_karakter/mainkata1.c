#include "mesinkar.h"
//#include "mesinkata.h"
#include "mesintoken.h"
#include <stdio.h>
#include "boolean.h"

int  main (){
    STARTTOKEN();
    while (!EndToken){
        if (CToken.val <0){
            printf("<'%c',-1>\n",CToken.tkn);
        }
        else
            printf("<'b',%d>\n",CToken.val);
            ADVTOKEN();
    }
    return 0;
}
