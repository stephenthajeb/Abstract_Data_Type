/*DRIVER QUEUE*/

#include "boolean.h"
#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>

void Tulis(PrioQueueChar Q){
    printf("Head %d\n",Head(Q));
    printf("Tail %d\n",Tail(Q));
    printf("NbElmt %d\n",NBElmt(Q));
}

int main(){

    PrioQueueChar Q;
    infotype X,Y;

    CreateEmpty(&Q,6);
    PrintPrioQueueChar(Q);
    printf("\n");
    printf("\n");

    Head(Q) = 4;
    Tail(Q) = 1;
    Q.T[6].prio = 2;
    Q.T[6].info = 'g';

    Q.T[5].prio = 2;
    Q.T[5].info = 'd';

    Q.T[1].prio = 4;
    Q.T[1].info = 'o';

    Q.T[4].prio = 1;
    Q.T[4].info = 'j';
    // PrintPrioQueueChar(Q);
    // printf("\n");
    // Tulis(Q);

    X.prio=4;
    X.info='z';
    Add(&Q,X);
    PrintPrioQueueChar(Q);
    Y.prio=0;
    Y.info='z';
    Add(&Q,Y);
    PrintPrioQueueChar(Q);
    printf("\n");
    // Tulis(Q);
}