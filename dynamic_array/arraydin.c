//Nama : Stephen Thajeb
//NIM : 13518150
//Nama File : arraydin.c
//Tanggal : 10 September 2019

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/* ********** SELEKTOR ********** */
// #define Neff(T) (T).Neff
// #define TI(T) (T).TI
// #define Elmt(T, i) (T).TI[(i)]
// #define MaxEl(T) (T).MaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
    TI(*T) = (ElType*) malloc ((maxel+1)*sizeof(ElType));
    Neff(*T) = 0;
    MaxEl(*T) = maxel;
}
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */

void Dealokasi(TabInt *T){
    free(TI(*T));
    MaxEl(*T) = 0;   
    Neff(*T)  = 0;    
}
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
    return (Neff(T));
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

int MaxElement(TabInt T){
    return (MaxEl(T));
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
    return (IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T){
    return(Neff(T));
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
    return ((i<=MaxEl(T)) && (i>=IdxMin));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i){
    return ((i<=GetLastIdx(T)) && (i>=GetFirstIdx(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
    return (NbElmt(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
    return (NbElmt(T)==MaxEl(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
    //kamus
    int N;

    //Algo
    scanf("%d",&N);
    while ((N>MaxEl(*T)||(N<0))){
        scanf("%d",&N);
    }
    Neff(*T) =N;
    if (Neff(*T) != 0){
        for (int i=IdxMin;i<=Neff(*T);i++){
            scanf("%d",&Elmt(*T,i));
        }
    } 
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab(TabInt T){
    printf("[");
    if (Neff(T)!=0){
        for (int i=IdxMin;i<Neff(T);i++){
            printf("%d,",Elmt(T,i));
        }
        printf("%d",Elmt(T,Neff(T)));
    }
    printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
    //Kamus
    TabInt T3;
    int i;
    //Algo  
    MakeEmpty(&T3,MaxEl(T1));
    Neff(T3) = Neff(T1);
    
    if (plus){
        for (i=IdxMin;i<=Neff(T1);i++){
            Elmt(T3,i) = Elmt(T1,i) + Elmt(T2,i); 
        }
    } else {
        for (i=IdxMin;i<=Neff(T1);i++){
            Elmt(T3,i) = Elmt(T1,i) - Elmt(T2,i);
        }
    }
    return (T3);
}
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
    if (Neff(T1) !=Neff(T2)){
        return (false);
    } else {
        for (int i=IdxMin;i<=Neff(T1);i++){
            if(Elmt(T1,i) != Elmt(T2,i)){
                return (false);
            }
        }
        return (true);
    }
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
    //Kamus
    boolean found;
    int i;

    //Algo
    found = false;

    if(IsEmpty(T)){
        return IdxUndef;
    } else {
        i = 1;
        while ((!found) && (i<=Neff(T))) {
            if (Elmt(T,i) == X){
                found = true;
            }
            i +=1;
        }//found == true or i>Neff(T)
        if (found){
            return (i-1);
        } else {  //not found
            return (IdxUndef);
        }
    }
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */

boolean SearchB(TabInt T, ElType X){
    //Kamus
    boolean found;
    int i;

    //Algo
    found = false;
    
    if (IsEmpty(T)){
        return (found);
    } else {
        i = 1;
        while ((!found) && (i<=Neff(T))) {
            if (Elmt(T,i) == X){
                found = true;
            }
            i +=1;
        }//found == true or i>Neff(T)
        return (found);        
    }
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
    //Kamus
    int temp_max = Elmt(T,1);
    int temp_min = Elmt(T,1);

    //Algo 
    for (int i=2;i<=Neff(T);i++){
        if(temp_max < Elmt(T,i)){
            temp_max = Elmt(T,i);
        }
        if (temp_min > Elmt(T,i)){
            temp_min = Elmt(T,i);
        }
    }
    *Max = temp_max;
    *Min = temp_min;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
    Dealokasi(Tout);
    MakeEmpty(Tout, MaxEl(Tin));
    Neff(*Tout) = Neff(Tin);
    for (int i=IdxMin;i<=Neff(Tin);i++){
        Elmt(*Tout,i) = Elmt(Tin,i); 
    }
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */

ElType SumTab(TabInt T){
    //Kamus
    int sum;
    //Algo
    sum = 0;
    if (IsEmpty(T)){
        return 0;
    } else {
        for (int i =IdxMin;i<=Neff(T);i++){
            sum += Elmt(T,i);
        }
    }
    return (sum);
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */

int CountX(TabInt T, ElType X){
    //Kamus
    int count;
    
    //Algo
    count = 0;
    if (IsEmpty(T)){
        return (count);
    } else {
        for(int i=IdxMin;i<=Neff(T);i++){
            if(Elmt(T,i)==X){
                count +=1;
            }
        }
        return (count);
    }
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */

boolean IsAllGenap(TabInt T){
    //kamus
    boolean cek;
    int i;
    //Algo
    cek = true;
    i = 1;

    if (IsEmpty(T)){
        return (!cek);
    } else {
        while (cek && (i<=Neff(T))){
            if (Elmt(T,i) %2 != 0){
                cek = false;
            } 
            i +=1;
        }
    return cek;
    }    
}
/* Menghailkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
    //Kamus
    int i,key,j;

    if (asc){
        if (Neff(*T) != 0){
            for (i=2;i<=Neff(*T);i++){
                key = Elmt(*T,i);
                j = i-1;
                while ((j>=1) && (Elmt(*T,j)>key)){
                    Elmt(*T,j+1) = Elmt(*T,j);
                    j = j-1; 
                }
                Elmt(*T,j+1) = key;
            }
        }
    } else {
        if (Neff(*T) != 0){
            for (i=2;i<=Neff(*T);i++){
                key = Elmt(*T,i);
                j = i-1;
                while ((j>=1) && (Elmt(*T,j)<key)){
                    Elmt(*T,j+1) = Elmt(*T,j);
                    j = j-1; 
            }
            Elmt(*T,j+1) = key;
            }
        }    
    }
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
    Neff(*T) +=1;
    Elmt(*T,Neff(*T)) = X;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
    *X = Elmt(*T,Neff(*T));
    Neff(*T) -= 1;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
    TI(*T) = (ElType*) realloc (TI(*T),(num+MaxEl(*T))*sizeof(int));
    MaxEl(*T) += num;
}
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabInt *T, int num){
    TI(*T) = (ElType*) realloc (TI(*T),(MaxEl(*T)-num)*sizeof(int));
    MaxEl(*T)  -= num;
}
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabInt *T){
    TI(*T) = (ElType*) realloc (TI(*T),Neff(*T)*sizeof(int));
    MaxEl(*T) = Neff(*T);
}
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
