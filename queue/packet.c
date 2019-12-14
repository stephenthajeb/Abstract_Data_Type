//Stephen Thajeb 13518150
//File : packet.c
//3 Oktober 2019

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

int main (){
    int n,detik;
    address i;
    PrioQueueChar pq;
    infotype pkg;

    scanf("%d",&n);
    CreateEmpty(&pq,n);
    detik = 1;

    while (detik <= n){
        scanf("%d %c",&Prio(pkg),&Info(pkg));
        Add(&pq,pkg);

        if (Tail(pq) >= Prio(pkg)){
            i = Prio(pkg);
            while (Prio(Elmt(pq,i)) == i){
                printf("%d %c\n",detik,Info(Elmt(pq,i)));
                i ++;
            }
        }
        detik ++;
    }
    return 0;
}