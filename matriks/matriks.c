//13518150 Stephen Thajeb
//matriks.c
//15 September 2019
/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "matriks.h"
#include <math.h>
/* Ukuran minimum dan maksimum baris dan kolom */
// #define BrsMin 1
// #define BrsMax 100
// #define KolMin 1
// #define KolMax 100

// typedef int indeks; /* indeks baris, kolom */
// typedef int ElType;
// typedef struct {
//     ElType Mem[BrsMax+1][KolMax+1];
//     int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
//     int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
// } MATRIKS;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

// /* *** Selektor *** */
// #define NBrsEff(M) (M).NBrsEff
// #define NKolEff(M) (M).NKolEff
// #define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
    return ((i>=BrsMin) && (i<=BrsMax) && (i>=KolMin) && (i<=KolMax)) && ((j>=BrsMin) && (j<=BrsMax) && (j>=KolMin) && (j<=KolMax));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
    return(BrsMin);
}
/* Mengirimkan indeks baris terkecil M */

indeks GetFirstIdxKol (MATRIKS M){
    return(KolMin);
}
/* Mengirimkan indeks kolom terkecil M */

indeks GetLastIdxBrs (MATRIKS M){
    return(NBrsEff(M));
}
/* Mengirimkan indeks baris terbesar M */

indeks GetLastIdxKol (MATRIKS M){
    return(NKolEff(M));
}
/* Mengirimkan indeks kolom terbesar M */

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    return (((i>=BrsMin)&&(i <= NBrsEff(M))) && (j <= NKolEff(M)&&(j>=KolMin)));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

ElType GetElmtDiagonal (MATRIKS M, indeks i){
    return (Elmt(M,i,i));
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
    for (int i=BrsMin;i<=NBrsEff(MIn);i++){
        for(int j=KolMin;j<=NKolEff(MIn);j++){
            Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
            NBrsEff(*MHsl)  = NBrsEff(MIn);
            NKolEff(*MHsl)  = NKolEff(MIn);
        }
    }
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    MakeMATRIKS(NB,NK,M);
    for(int i=BrsMin;i<=NBrsEff(*M);i++){
        for(int j=KolMin;j<=NKolEff(*M);j++){
            scanf("%d",&Elmt(*M,i,j));
        }
    }
}
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void TulisMATRIKS (MATRIKS M){
    for(int i=BrsMin;i<=NBrsEff(M);i++){
        if (i != NBrsEff(M)){
            for(int j=KolMin;j<=NKolEff(M);j++){
                if (j != NKolEff(M)){
                    printf("%d ",Elmt(M,i,j));    
                } else { //untuk kolom terakhir
                    printf("%d\n",Elmt(M,i,j));
                }
            }
        } else { //untuk baris terakhir
            for(int j=KolMin;j<=NKolEff(M);j++){
                if (j != NKolEff(M)){
                    printf("%d ",Elmt(M,i,j));    
                } else { //untuk baris terakhir kolom terakhir
                    printf("%d",Elmt(M,i,j));
                }
            }
        }    
    }
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
    for(int i=BrsMin;i<=NBrsEff(M1);i++){
        for(int j=KolMin;j<=NKolEff(M1);j++){
            Elmt(M1,i,j) += Elmt(M2,i,j);
        }
    }
    return (M1);
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
    for(int i=BrsMin;i<=NBrsEff(M1);i++){
        for(int j=KolMin;j<=NKolEff(M2);j++){
            Elmt(M1,i,j) -= Elmt(M2,i,j);
        }
    }
    return (M1);
}

/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
    //Kamus Lokal
    MATRIKS M3;
    //Algoritma
    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&M3);
    for(int i=BrsMin;i<=NBrsEff(M3);i++){
        for(int j=KolMin;j<=NKolEff(M3);j++){
            Elmt(M3,i,j) = 0;
            for (int k=KolMin;k<=NKolEff(M1);k++){
                Elmt(M3,i,j) += Elmt(M1,i,k) * Elmt(M2,k,j);
            }
        }
    }
    return (M3);
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */

MATRIKS KaliKons (MATRIKS M, ElType X){
    for(int i=BrsMin;i<=NBrsEff(M);i++){
        for(int j=KolMin;j<=NKolEff(M);j++){
            Elmt(M,i,j) *= X;
        }
    }
    return (M);
}
/* Mengirim hasil perkalian setiap elemen M dengan X */

void PKaliKons (MATRIKS * M, ElType K){
    *M = KaliKons(*M,K); 
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
    // //Kamus LokaL
    //Algoritma
    if (NBElmt(M1)!=NBElmt(M2)){
        return false;
    } else {
        for (int i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
            for(int j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
                if (Elmt(M1,i,j) != Elmt(M2,i,j)){
                    return false;
                }
            }
        }
        return true;
    }
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */

boolean NEQ (MATRIKS M1, MATRIKS M2){
    return (!EQ(M1,M2));
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */

boolean EQSize (MATRIKS M1, MATRIKS M2){
    return ((NBrsEff(M1)==NBrsEff(M2)) && (NKolEff(M1)==NKolEff(M2))) ; 
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
    return (NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
    return (NBrsEff(M)==NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */

boolean IsSimetri (MATRIKS M){
    if (IsBujurSangkar(M)){
        for (int i=BrsMin;i<=GetLastIdxBrs(M);i++){
            for(int j=KolMin;j<=i;j++){
                if (Elmt(M,i,j)!=Elmt(M,j,i)){
                    return false;
                }
            }
        }
        return true;
    }
    else {
        return false;
    }
}

/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */

boolean IsSatuan (MATRIKS M){
    //Kamus
    int i = BrsMin;
    int j = KolMin;
    boolean cek=true;

    //Algoritma
    if (IsBujurSangkar(M)){
        while (cek && i<=GetLastIdxBrs(M)){
            if (i==j){
                cek = (Elmt(M,i,j)==1);
            }else {
                cek = (Elmt(M,i,j)==0);
            }
            j+=1;

            if(j>GetLastIdxKol(M)){
                j=GetFirstIdxKol(M);
                i++;
            }
        }  
        return cek;
    } else {
        return false;
    }
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */

boolean IsSparse (MATRIKS M){
    //KAMUS
    int counter=0;
    //Algo
    for(int i=BrsMin;i<=NBrsEff(M);i++){
        for(int j=KolMin;j<=NKolEff(M);j++){
            if(Elmt(M,i,j)!=0){
                counter +=1;
            }
        }
    }
    return (counter <= 0.05*NBElmt(M));
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */

MATRIKS Inverse1 (MATRIKS M){
    //Kamus
    int X=-1;
    //Algoritma
    return (KaliKons(M,X));
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */

float Determinan (MATRIKS M){
    //Kamus
    int i,j,k;
    float scale;
    float temp;
    int next; // index yang menunjukkan index baris berikutnya dr current row
    int swap=0; //jumlah pertukuran baris yang terjadi
    float det=1;
    float REF[GetLastIdxBrs(M)][GetLastIdxKol(M)];

    for (int i=0;i<GetLastIdxBrs(M);i++){
        for(int j=0;j<GetLastIdxKol(M);j++){
            REF[i][j] = (float) Elmt(M,i+1,j+1); //copy matriks dan typecasting elemen menjadi float
        }
    }
    for(i=0;i<GetLastIdxBrs(M);i++){
        if(REF[i][i]==0){
            next = i+1;
            if (next < GetLastIdxBrs(M)){
                do{
                    for (j=0;j<GetLastIdxBrs(M);j++){
                        temp = REF[i][j];
                        REF[i][j]=REF[next][j];
                        REF[next][j] = temp;
                }
                next  +=1;
                swap  +=1;                
                } while (REF[i][i]==0 && i<GetLastIdxBrs(M));
            }
        }

        for (j=i+1;j<GetLastIdxBrs(M);j++){
            float scale = REF[j][i] / REF[i][i];
            for(k=0;k<GetLastIdxKol(M);k++){
                REF[j][k]= REF[j][k] - (REF[i][k]*scale);
            }
        }
    }

    for (i=0;i<GetLastIdxBrs(M);i++){
        det *= REF[i][i];
    }
    if(swap%2 ==1){
        det = det*(-1);
    }
    if (det == -0){
        det =0;
    }
    return det;
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */

void PInverse1 (MATRIKS * M){
    *M = Inverse1(*M);
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

void Transpose (MATRIKS * M){
    //Kamus
    ElType tempElmt;
    //Algoritma
    for (int i=BrsMin;i<=NBrsEff(*M);i++){
        for (int j=i+1;j<=NKolEff(*M);j++){
            tempElmt = Elmt(*M,j,i);
            Elmt(*M,j,i) = Elmt(*M,i,j);
            Elmt(*M,i,j) = tempElmt;
        }
    }
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */


/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M,indeks i){
	float sum=0;
	
	for(int j=1;j<=GetLastIdxKol(M);j++){
		sum += Elmt(M,i,j);
	}
	return (sum/NKolEff(M));
}
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */

float RataKol (MATRIKS M, indeks j){
	float sum=0;
	
	for(int i=1;i<=GetLastIdxBrs(M);i++){
		sum += Elmt(M,i,j);
	}
	return (sum/NBrsEff(M));	
}
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min){
	*max = Elmt(M,i,1);
	*min = Elmt(M,i,1);
	for (int j=1;j<=GetLastIdxKol(M);j++){
		if (*max<Elmt(M,i,j)){
			*max= Elmt(M,i,j);
		} 
		if (*min >Elmt(M,i,j)){
			*min = Elmt(M,i,j);
		}
	}
}
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min){
	*max = Elmt(M,1,j);
	*min = Elmt(M,1,j);
	for (int i=1;i<=GetLastIdxBrs(M);i++){
		if (*max<Elmt(M,i,j)){
			*max= Elmt(M,i,j);
		} 
		if (*min >Elmt(M,i,j)){
			*min = Elmt(M,i,j);
		}
	}
}
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */

int CountXBrs (MATRIKS M, indeks i, ElType X){
	int counter=0;
	
	for(int j=1;j<=GetLastIdxKol(M);j++){
		if(X==Elmt(M,i,j)){
			counter +=1;
		}
	}
	return counter;
}
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */

int CountXKol (MATRIKS M, indeks j, ElType X){
	int counter=0;
	
	for(int i=1;i<=GetLastIdxBrs(M);i++){
		if(X==Elmt(M,i,j)){
			counter +=1;
		}
	}
	return counter;
}
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
