#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include "boolean.h"

int NSubset(Kata key,Kata random){
    int freq=0;
    if(key.Length > random.Length){
        freq =0;
    }else { //key.Length <= random length
        for (int i=1;i<=(random.Length-key.Length+1);i++){
            boolean sama=true;
            int j=1;
            while (sama && j<=key.Length) {
                if(key.TabKata[j] != random.TabKata[j+i-1]){
                    sama =false;
                }
                j ++;
            }
            if(sama){
                freq +=1;
            }
        }
    }
    return freq;
}

int main (){
    Kata key;
    Kata random;
    int counter=0;
    
    STARTKATA();
    key=CKata;

    ADVKATA();
    if(EndKata){
        printf("%d\n",counter);
    } else {
        while (!EndKata){       
            counter += NSubset(key,CKata);
            ADVKATA();
            }
        printf("%d\n",counter);
    }
    return 0;
}