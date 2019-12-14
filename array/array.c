//Nama : Stephen Thajeb
//NIM : 13518150
//Nama File : array.c
//Tanggal : 3 September 2019
//Deskripsi: ADT array


#include <stdio.h>
#include "array.h"


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T){
    Neff(*T) = 0;
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
    return Neff(T);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

int MaxNbEl (TabInt T){
    return (IdxMax);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
    return (IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabInt T){
    return (Neff(T));
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
    return ((i>=IdxMin) && (i<=IdxMax));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i){
    return ((i>=IdxMin)&&(i<=Neff(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
    return (Neff(T) == 0);
}

/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
    return (Neff(T) == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
    //Kamus lokal
    int N;
    //Algoritma
    scanf("%d",&N);
    while ((N<0) || (N>MaxNbEl(*T))) {
        scanf("%d",&N);
    }//0<= N < MaxNbEl(*T) 
    Neff(*T) = N; 
    if(N > 0){
        for (int i=1;i <= N;i++ ){
            scanf("%d",&Elmt(*T,i));
        }
    }
}

/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */

void BacaIsiTab (TabInt * T){
    int masukan,i=IdxMin;
    Neff(*T) =0;
    scanf("%d",&masukan);
    if (masukan == -9999){
        MakeEmpty(T);
    } else {
        while ((masukan != -9999)&& (i<=IdxMax)){
            Elmt(*T,i) = masukan;
            Neff(*T) +=1; 
            scanf("%d",&masukan);
            i +=1;
        }
    }
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */

void TulisIsi (TabInt T){
    if(Neff(T)==0){
        printf("Tabel kosong\n");
    } else {
        for (int i=IdxMin;i<=Neff(T);i++){
            printf("[%d]%d\n",i,Elmt(T,i));
        }
    }
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
void TulisIsiTab (TabInt T){
    //Kamus
    int i;

    if(Neff(T)==0){
        printf("[]");
    }
    else{ //Neff(T) != 0
        printf("[");
        for (i=IdxMin;i<Neff(T);i++){
            printf("%d,",Elmt(T,i));
        }
        printf("%d]",Elmt(T,i));
    } 
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
TabInt PlusTab (TabInt T1, TabInt T2){
    //Kamus
    TabInt T3;
    //Algo
    Neff(T3) = Neff(T1);
    for (int i=IdxMin;i<=Neff(T1);i++){
        Elmt(T3,i) = Elmt(T1,i) + Elmt(T2,i);
    }
    return (T3);
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */

TabInt MinusTab (TabInt T1, TabInt T2){
    //Kamus
    TabInt T3;
    //Algo
    Neff(T3) = Neff(T1);
    for (int i=IdxMin;i<=Neff(T1);i++){
        Elmt(T3,i) = Elmt(T1,i) - Elmt(T2,i);
    }
    return (T3);
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

TabInt KaliTab (TabInt T1, TabInt T2){
    //Kamus
    TabInt T3;
    //Algo
    Neff(T3) = Neff(T1);
    for (int i=IdxMin;i<=Neff(T1);i++){
        Elmt(T3,i) = Elmt(T1,i) * Elmt(T2,i);
    }
    return (T3);
}

/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
TabInt KaliKons (TabInt Tin, ElType c){
    for (int i=IdxMin;i<=Neff(Tin);i++){
        Elmt(Tin,i) = Elmt(Tin,i) * c;
    }
    return (Tin);
}
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */

boolean IsEQ (TabInt T1, TabInt T2){
    //Kamus
    boolean cek=true;
    int i=1;
    //Algo
    if(Neff(T1) != Neff(T2)){
        return false;
    } else {
        while ((cek) && (i<=Neff(T1))){
            if (Elmt(T1,i) != Elmt(T2,i)){
                cek = false;
            }
                i +=1;
            }//cek false atau i> Neff(T1)
        return (cek);
        }
    }
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */

boolean IsLess (TabInt T1, TabInt T2){
    if (Neff(T1)<Neff(T2)){
        return true;
    } else if (Neff(T1)>Neff(T2)){
        return false;
    } else { // Neff(T1) == Neff(T2)
        if (IsEQ(T1,T2)){
                return false;
        } else { // ada elemen T1 yang nilainya berbeda dengan T2
            for (int i=1;i<=Neff(T1);i++){
                if (Elmt(T1,i) > Elmt(T2,i)){
                    return false;
                } else if (Elmt(T1,i) < Elmt(T2,i)){ 
                    return true;
                }
            }
        }  
    }
}
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */

IdxType Search1 (TabInt T, ElType X){
    //Kamus
    IdxType i =1;
    IdxType i_search;

    //Algoritma
    if(Neff(T)==0){
        i_search = IdxUndef;
    } else {
        while ((i<=Neff(T)) && (Elmt(T,i) != X)){
            i = i+1;
        }//keluar loop jika i>Neff(T) atau Elmt(T,i) == X
        if(Elmt(T,i)==X){
            i_search = i;
        } else {
            i_search = IdxUndef;
        }
    }
    return (i_search);
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
IdxType Search2 (TabInt T, ElType X){
    //Kamus
    IdxType i_search,i=1;
    boolean found=false;
    
    //Algoritma
    if(Neff(T)==0){
        i_search = IdxUndef;   
    }
    else {
        while ((found==false) && (i<=Neff(T))) {
            if(Elmt(T,i)==X){
                found = true;
            }
            i+=1;
        }
        if(found == false){
            i_search = IdxUndef;   
        } else {
            i_search = i-1;
        }
    }
    return (i_search);
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */

boolean SearchB (TabInt T, ElType X){
    //Kamus lokal
    boolean found = false;
    IdxType i=1;

    //Algo
    if(Neff(T)==0){
        return (found);   
    } else { //tidak kosong
        while ((found==false) && (i<=Neff(T))) {
                if (Elmt(T,i) == X){
                    found = true;
                }
                i +=1;
            }
    }
    return (found);
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */

boolean SearchSentinel (TabInt T, ElType X){
    //Kamus lokal
    int i =Neff(T);

    //Algo
    Elmt(T,0) = X;
    while ((Elmt(T,i) != X))  {
        i -=1;
    }
    return (i != 0);
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
    //Kamus
    ElType temp;
    //Algo
    temp = Elmt(T,IdxMin); //set nilai awal temp
    for (int i=2;i<=Neff(T);i++){
        if (temp < Elmt(T,i)){
            temp = Elmt(T,i);
        }
    }
    return (temp);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
ElType ValMin (TabInt T){
    //Kamus
    ElType temp;
    //Algo
    temp = Elmt(T,IdxMin); //set nilai awal temp
    for (int i=2;i<=Neff(T);i++){
        if (temp > Elmt(T,i)){
            temp = Elmt(T,i);
        }
    }
    return (temp);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */

IdxType IdxMaxTab (TabInt T){
    Search1(T,ValMax(T));
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
IdxType IdxMinTab (TabInt T){
    Search1(T,ValMin(T));
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout){
    Neff(*Tout) = Neff(Tin);
    for (int i =1;i<=Neff(Tin);i++){
        Elmt(*Tout,i) = Elmt(Tin,i); 
    }
}
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
TabInt InverseTab (TabInt T){
    TabInt T2;
    CopyTab(T,&T2);
    Neff(T2)=Neff(T);
    for (int i =1;i<=Neff(T);i++){
        Elmt(T2,Neff(T)-i+1) = Elmt(T,i); 
    }
    return (T2);
}
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
boolean IsSimetris (TabInt T){
    /* KAMUS LOKAL */
    int i = IdxMin, j = NbElmt(T);
    /* ALGORITMA */
    while (i<=j) {
        if (Elmt(T, i) != Elmt(T, j)) {
            return false;
        }
        i++; j--;
    }
    return true;
}

/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T){
    //Kamus
    ElType temp;
    int idxmax,max,i,j;
    //Algo
    for (i=IdxMin;i<=Neff(*T)-1;i++){
        max=Elmt(*T,i);
        idxmax = i;
        for (j=i+1;j<=Neff(*T);j++){
            if(Elmt(*T,j) > max){
                max = Elmt(*T,j);
                idxmax = j;
            }
        }
        temp = Elmt(*T,i);
        Elmt(*T,i) = max;
        Elmt(*T,idxmax) = temp;
    }
}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */

void InsSortAsc (TabInt * T){
    int i,key,j;
    for (i=2;i<Neff(*T);i++){
        key = Elmt(*T,i);
        j = i-1;

        while ((j>=1) && (Elmt(*T,j)>key)){
            Elmt(*T,j+1) = Elmt(*T,j);
            j = j-1; 
        }
        Elmt(*T,j+1) = key;
    }
}
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X){
    Neff(*T) +=1;
    Elmt(*T,Neff(*T)) = X;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

void AddEli (TabInt * T, ElType X, IdxType i){
    //Kamus
    int j;
    //Algo
    Neff(*T) +=1;
    j=Neff(*T);
    while (j > i){
        Elmt(*T,j) = Elmt(*T,j-1);
        j-=1;
    }
    Elmt(*T,i) = X;
}
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X){
    *X = Elmt(*T,NbElmt(*T));
    Neff(*T) -=1;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
void DelEli (TabInt * T, IdxType i, ElType * X){
    *X = Elmt(*T,i);
    for (int j=i;j<Neff(*T);j++){
        Elmt(*T,j) = Elmt(*T,j+1);
    }
    Neff(*T) -=1;
}
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X){
    if (SearchSentinel(*T,X)){
        printf("nilai sudah ada\n");
    } else {
        AddAsLastEl (T,X);
    }
}
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
    Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
    dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen fjika belum ada */

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X){
    //Kamus
    IdxType i =1;

    //Algo
    if(Neff(T)==0){
        return ( IdxUndef);
    } else {
        for (i=IdxMin;i<=Neff(T);i++){
            if (Elmt(T,i) ==X){
                return i;
            }
            if(Elmt(T,i) > X){
                return IdxUndef;
            }
        }
    }
}
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
ElType MaxUrut (TabInt T){
    return(Elmt(T,Neff(T)));
}
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
ElType MinUrut (TabInt T){
    return (Elmt(T,IdxMin));
}
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min){
    *Max = MaxUrut(T); 
    *Min = MinUrut(T);
}
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
void Add1Urut (TabInt * T, ElType X){
    //Kamus
    IdxType i = 1;

    while ((Elmt(*T,i)<X)){
        i+=1;
    }//Elmt(T,i) >= X atau i>IdxMax
    
    //Memanggil prosedur AddEli
    if(Neff(*T) < IdxMax){
        AddEli (T, X, i);
    }
}
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */

void Del1Urut (TabInt * T, ElType X){
    int i =1;
    while ((Elmt(*T,i)<X)){
        i+=1;
    }//Elmt(T,i) >= X 
    if(Elmt(*T,i) == X){
        DelEli(T,i,&X);   
    }
}
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
