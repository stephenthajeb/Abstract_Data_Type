/* File: mjam.c */
// Nama : Stephen Thajeb
// NIM : 13518150
/* Tanggal: 01 September 2019 */
/* Deskripsi : mengetahui waktu awal dan akhir record telepon */ 

#include "jam.h"
#include <stdio.h>
#include <math.h>

int main() {
    //Kamus
    int N;
    long awal,akhir;
    JAM J1,J2;
    JAM j_awal,j_akhir;
    //Algo
    scanf("%d",&N);
    awal  = 86401; // dummy value 
    akhir = -1; // dummy value
    for (int i=1;i<=N;i++){
        printf("[%d]\n",i);
        BacaJAM (&J1);
        BacaJAM(&J2);

        if (JLT (J1,J2)){
            printf("%ld\n",Durasi(J1,J2));
        } else {
            printf("%ld\n",Durasi(J2,J1));
        }
        if((awal > JAMToDetik(J1)) || ((awal > JAMToDetik(J2)))){
            if (JLT (J1,J2)){ //J1 < J2
                awal = JAMToDetik(J1);
            } else { //J2 < J1  
                awal = JAMToDetik(J2);
            }
        }
        if((akhir < JAMToDetik(J1)) || ((akhir < JAMToDetik(J2)))){
            if (JGT (J1,J2)){ //J1 > J2
                akhir  = JAMToDetik(J1);
            } else { 
                akhir = JAMToDetik(J2);
            }
        }
    }
    j_awal   = DetikToJAM(awal);
    j_akhir  = DetikToJAM(akhir);
    TulisJAM(j_awal);
    printf("\n");
    TulisJAM(j_akhir);
    printf("\n");
    return 0; 
}