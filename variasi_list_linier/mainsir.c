#include "listsirkuler.h"
// #include "listdp.h"
#include <stdio.h>


int NbElmt(List L){
    address P = First(L);
    int counter = 0;

    if (IsEmpty(L)){
        return counter;
    } else {
        counter +=1; 
    }

    while (Next(P) != First(L)){
        P = Next(P);
        counter +=1;
    }
}

int CountX (List L,infotype X,char sign){
    int temp1,temp2,temp3;
    address P;
    int nb;

    P = First(L);
    temp1=0;
    temp2=0;
    temp3=0;

    nb = NbElmt(L);

    if (IsEmpty(L)){
        return 0;
    } else {
        
        while (nb != 0){ 
            if (Info(P) > X){
                temp1 +=1;
            } else if (Info(P) == X){
                temp2 ++;
            } else {
                temp3 ++;   
            }
            P = Next(P);
            nb -=1;
        } // P == Nil
        if (sign == '>'){
            return temp1;
        } else if (sign == '='){
            return temp2;
        } else {
            return temp3;
        }
    }   
}

boolean isExist (List L, infotype X){
    address P;
    int ctr=NbElmt(L);

    P = First(L);
    while (ctr != 0 ){
        if (Info(P) == X){
            return true;
        } else {
            P = Next(P);
            ctr -=1;
        }
    }
    return false; 
}

infotype Max (List L){
    infotype temp;
    address P=First(L);
    int nb = NbElmt(L);
    temp = Info(P);

    while (nb != 0){
        if (temp < Info(P)){
            temp = Info(P);
        } else {
            P = Next(P);
            nb -=1;
        }
    }
    return temp;
}

address AdrMax (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
	return Search(L,Max(L));
}

void AscOrderList(List *L){
/* IS : L terdefinisi, tidak kosong */
/* FS : Elemen-elemen L terurut membesar */

    List L2;
    CreateEmpty(&L2);

    while (!IsEmpty(*L)){
        InsVFirst(&L2,Max(*L));
        DelP(L,Max(*L));
    }//IsEmpty(*L)
    First(*L) = First(L2);
}

void FilterList (List *L,infotype X){
    /* IS : L terdefinisi, mungkin kosong. X terdefinisi. */
    /* FS : Semua elemen L dengan info bernilai X dihapus dan
    didealokasi dari list L. L mungkin menjadi kosong. */

    //mirip dengan DelP
    address P;
    P = First(*L);
    while (isExist(*L,X)){
        DelP(L,X);
    }

    while (P != Nil){
        if (Info(P) == X){
            DelP (L,X);
        }
        P = Next(P);
    }
}

void SplitList (List L,List *LGenap, List *LGanjil){
    /* IS : L mungkin kosong, L1 dan L2 sembarang */
    /* FS : Berdasarkan L, dibentuk dua buah list LGenap dan
    LGanjil. LGenap berisi semua elemen L yang genap, sedangkan
    LGanjil berisi semua elemen L yang ganjil. Setiap elemen LGenap
    dan LGanjil harus dialokasi sebagai elemen baru. Jika ada
    elemen yang gagal dialokasi, maka list yang bersangkutan
    menjadi kosong dan semua elemen yang sudah telanjur dialokasi,
    didealokasi (bisa LGenap atau LGanjil, atau dua-duanya). L
    tetap.
    Perhitungan elemen L, dimulai dari 1 (elemen pertama L
    merupakan elemen ke-1) */
    
    address P;

    CreateEmpty(LGenap);
    CreateEmpty(LGanjil);

    P = First(L);
    //Dialokasi dahulu ???
    while (P != Nil){
          if (Info(P) % 2 == 0){
              InsVLast(LGenap,Info(P));
          } else { //gankil
              InsVLast(LGanjil,Info(P));
          }
          P = Next(P);
    }
}

boolean isSubList (List L1,List L){
    /* Menghasilkan true jika list L1 muncul sebagai sublist dari
    L. L1 merupakan sublist dari L bila L1 muncul pada L secara
    sekuensial. */ 
    boolean sub=true;
    address p,p1;

    p  = First(L);
    p1 = First(L1);
    
    if (NbElmt(L1) > NbElmt(L)){
        sub = false;
    } else {
        if (!IsEmpty(L)){
            while ((p1 != Nil) && (sub)){
                if (Info(p) != Info(p1)){
                    sub = false;
                } else {
                    p = Next(p);
                    p1= Next(p1);
                }
            }
        } else {
            sub = false;
        }
    }
    
    return sub;


}

float Average (List L){
    float avg;
    address P;
    int nb = NbElmt(L);

    P = First(L);
    avg = 0;
    if (IsEmpty (L)){
        return avg;
    } else {
        while (nb != 0){
            avg += Info(P);
            P = Next(P);
            nb -=1;
        }
        printf("%f",avg);
        printf("%d",NbElmt(L));
        avg /= NbElmt(L);
        return avg;
    }
}

int Jarak (List L,infotype X, infotype Y){
/* Mengirimkan jarak (banyaknya elemen) antara elemen dengan info X
dan elemen dengan info Y (tidak termasuk elemen X dan Y sendiri).
Jika X dan Y tepat bersebelahan, jaraknya adalah 0.
Jika ada lebih dari satu elemen X dan/atau Y di L maka digunakan
elemen X dan Y yang pertama kali ditemukan.
Urutan kemunculan X dan Y bebas, artinya X dapat muncul sebelum atau
sesudah Y. */
/* Prekondisi : X dan Y pasti berbeda dan pasti ada di L, sehingga L
tidak mungkin kosong. */

    infotype temp;
    address P;
    P = First(L);
    boolean found;
    found = false;
    int counter;
    counter =0;
    

    while (P != Nil){
        if (((Info(P) == X) || (Info(P)==Y)) && (!found)){
            if (Info(P) == X){
                temp = Y;
            } else {
                temp = X;
            }
            found = true;
        }
        
        if (found) {
            if (Info(Next(P)) == temp){
                return (counter);
            } else {
                counter +=1;
            }
        }

        P = Next(P);   
    }

    // address P,Px,Py;
	// int sum = 0;
	// /*algoritma*/
	// Px = Search(L,X);
	// Py = Search(L,Y);
	// P = Next(Px);
	// Py = Search(L,Y);
	// while(P != Py)
	// 	sum += 1;
	// return sum;
}

void InverseList (List *L){
/* I.S. L terdefinisi, mungkin kosong */
/* F.S. Elemen list dibalik : Elemen terakhir menjadi elemen pertama,
dan seterusnya */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi */
    address P;
    P = First(*L);
    infotype temp;
    List Ltemp;
    infotype pertama;

    CreateEmpty(&Ltemp);
    DelVFirst(L,&pertama);

    if (!IsEmpty(*L)){
        while (P != Nil){
            DelVLast(L,&temp);
            // printf("%d",temp);
            InsVLast(&Ltemp,temp);
            P = Next(P);
            PrintInfo(Ltemp);    
        }
        InsVLast(&Ltemp,pertama);
        PrintInfo(Ltemp);
    }

}

int main(){
    List L,LO,LE;

    infotype x;

    CreateEmpty(&L);
    CreateEmpty(&LE);
    CreateEmpty(&LO);
    for (int i=1;i<=5;i++){
        scanf("%d",&x);
        InsertLast(&L,Alokasi(x));
    }

    PrintInfo(L);
    printf("%d",Max(L));
    printf("\n");
    // printf("%d",CountX(L,4,'='));
    printf("\n");
    printf("%f",Average(L));
    printf("\n");
    AscOrderList(&L);
    PrintInfo(L);

    // if (isExist(L,2)){
    //     printf("hehe");
    // } else {
    //     printf("nono");
    // }

    // FilterList(&L,2);
    // PrintInfo(L);
    // printf("\n");
    // SplitList(L,&LE,&LO);
    // PrintInfo(LE);
    // PrintInfo(LO);
    // if (isSubList(LO,L)){
    //     printf("ISSUBLIST");
    // } else {
    //     printf("nonono");
    // }

    // printf("%d",Jarak(L,2,4));
    // InverseList(&L);
    // PrintInfo(L);
    
    return 0;
}