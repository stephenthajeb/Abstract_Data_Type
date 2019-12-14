//Stephen Thajeb 13518150
//10 November 2019
//adt bintree.c

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

// #ifndef _BINTREE_H_
// #define _BINTREE_H_

/* Modul lain yang digunakan : */
// #include "listrek.h"
// #include "boolean.h"

/* #define Nil NULL */ /* konstanta Nil sesuai pada modul listrek */

/* *** Definisi Type Pohon Biner *** */
/* typedef int infotype; */ /* type infotype sesuai pada modul listrek */
// typedef struct tNode *addrNode;
// typedef struct tNode {
//   infotype info;
//   addrNode left;
//   addrNode right;
// } Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
// typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
// #define Akar(P) (P)->info
// #define Left(P) (P)->left
// #define Right(P) (P)->right

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R){
    //Kamus
    BinTree Tree;
    //Algo
    Tree = AlokNode(Akar);
    if (Tree != Nil){
        Left(Tree)  = L;
        Right(Tree) = R;
    }
    return (Tree);
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P){
    //Kamus
    
    //Algo
    *P = Tree(Akar,L,R);
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = Nil jika alokasi gagal. */
BinTree BuildBalanceTree(int n){
    //Kamus
    infotype input;
    int nl,nr;
    BinTree L,R,P;
    if (n == 0){
        return Nil;
    } else {
        scanf("%d",&input);
        P = AlokNode(input);
        if (P != Nil){
            nl= n/2;
            nr= n - nl -1;
            L = BuildBalanceTree(nl);
            R = BuildBalanceTree(nr);
            Left(P)  = L;
            Right(P) = R;
        }
        return P;
    }
}
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
/* Jika n == 0, kembalikan Nil.
   Mula-mula, baca nilai dari root dari stdin, lalu bangun pohon biner di kiri
   (dengan membaca dari stdin) lalu di tree kanan (dengan membaca dari stdin). 
   misal dari stdin: 1, 2, 3, 4, 5, 6, 7, hasilnya:
       1
     2   5
    3 4 6 7
  */

/* Manajemen Memory */
addrNode AlokNode(infotype X){
    //Kamus
    addrNode P;
    //Algo
    P = (addrNode) malloc (sizeof (Node));
    if (P != Nil){
        Akar(P)  = X;
        Left(P)  = Nil;
        Right(P) = Nil;
    }
    return P;
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P){
    //Kamus
    
    //Algo
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P){
    //Kamus
    
    //Algo
    return (P == Nil);
}
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P){
    //Kamus
    
    //Algo
    if (IsTreeEmpty(P)){
        return false;
    } else {
        return ((Left(P)== Nil) && (Right(P)==Nil));
    }
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P){
    //Kamus
    
    //Algo
    return (P != Nil) && (Right(P) == Nil) && (Left(P) != Nil);
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P){
    //Kamus
    
    //Algo
    return (P != Nil) && (Left(P) == Nil) && (Right(P) != Nil);
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P){
    //Kamus
    
    //Algo
    return (P != Nil) && (Left(P) != Nil) && (Right(P) != Nil);
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/* *** Traversal *** */
void PrintPreorder(BinTree P){
    //Kamus
    
    //Algo
    // printf("(");
    // if (!IsTreeEmpty(P)){
    //     printf("%d",Akar(P));
    //     PrintPreorder(Left(P));
    //     PrintPreorder(Right(P));
    // }
    // printf(")");
    if(IsTreeEmpty(P)){
		printf("()");
	} else {
		printf("("); printf("%d",Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
		printf(")");
	}
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintInorder(BinTree P){
    //Kamus
    
    //Algo
    // printf("(");
    // PrintInorder(Left(P));
    // if (!IsTreeEmpty(P)){
    //     printf("%d",Akar(P));
    // }
    // PrintInorder(Right(P));
    // printf(")");
    if(IsTreeEmpty(P)){
		printf("()");
	} else {
		printf("(");
		PrintInorder(Left(P));
		printf("%d",Akar(P));
		PrintInorder(Right(P));
		printf(")");
	}
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintPostorder(BinTree P){
    //Kamus
    
    //Algo
    // printf("(");
    // PrintInorder(Left(P));
    // PrintInorder(Right(P));
    // if (!IsTreeEmpty(P)){
    //     printf("%d",Akar(P));
    // }
    // printf(")");
    if(IsTreeEmpty(P)){
		printf("()");
	} else {
		printf("(");
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%d", Akar(P));
		printf(")");
	}
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

void PrintTreeRecc (BinTree P, int h, int Rec)
{
	/*Kamus Lokal*/
	int i;

	/*Algoritma*/
	if(IsTreeEmpty(P)){
		/*do nothing*/
	} else {

		/*Untuk indentasi*/
		for(i=1; i<=h*(Rec-1); i++){
			printf(" ");
		}
		printf("%d\n", Akar(P));

		/*Rekurens*/
		if(Left(P) != Nil){
			PrintTreeRecc(Left(P), h, Rec+1);
		}
		if(Right(P) != Nil){
			PrintTreeRecc(Right(P), h, Rec+1);
		}
	}
}

void PrintTree(BinTree P, int h){
    //Kamus

    //Algo
    PrintTreeRecc(P,h,1);
}
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X){
    //Kamus
    
    //Algo
    if (IsTreeEmpty(P)){
        return false;
    } else {
        if (Akar(P)==X){
            return true;
        } else {
            return ((SearchTree(Left(P),X)) || (SearchTree(Right(P),X)));
        }
    }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P){
    //Kamus
    
    //Algo
    if (IsTreeEmpty(P)){
        return 0;
    }else {
        return (1+(NbElmt(Left(P))+NbElmt(Right(P))));
    }
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun1 (BinTree P){
    if (IsTreeOneElmt(P)){
            return 1;
        } else {
            if (IsUnerLeft(P)){
                return (NbDaun1(Left(P)));
            } else if (IsUnerRight(P)){
                return (NbDaun1(Right(P)));
            } else if (IsBiner(P)) {
                return (NbDaun1(Left(P))+NbDaun1(Right(P)));
            }
        }
}

int NbDaun(BinTree P){
    //Kamus
    
    //Algo
    if (IsTreeEmpty(P)){
        return 0;
    }else {
        return (NbDaun1(P));
    }

}
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P){
    //Kamus
    
    //Algo
    if (IsTreeEmpty(P)){
        return true;
    } else if (IsTreeOneElmt(P)){
        return true;
    } else {
        if (IsUnerLeft(P)){
            return (IsSkewLeft(Left(P)));
        } else {
            return false;
        }
    }
}
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P){
    //Kamus
    
    //Algo
    if (IsTreeEmpty(P)){
        return true;
    } else if (IsTreeOneElmt(P)){
        return true;
    } else {
        if (IsUnerRight(P)){
            return (IsSkewRight(Right(P)));
        } else {
            return false;
        }
    }
}
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level(BinTree P, infotype X){
    //Kamus
    
    //Algo
    if (SearchTree(P, X)){
        if (IsTreeOneElmt(P)){
            return 1;
        }
        else{
            return (1 + Level(Left(P),X) + Level(Right(P),X));
        }
	}else{//g ad di tree
		return 0;
	}
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
int Tinggi(BinTree P){
    //Kamus
    
    //Algo
    if (IsTreeEmpty(P)){
        return 0;
    }else{
        if (Tinggi(Left(P)) > Tinggi(Right(P))){
            return (1+Tinggi(Left(P)));
        }
        else{
            return (1+Tinggi(Right(P)));
        }
    }
}
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X){ //TC 37 38
    //Kamus
    
    //Algo
    if (IsTreeEmpty(*P)){
        *P = AlokNode(X);
    } else {
        AddDaunTerkiri(&Left(*P),X);
    }
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri){
    //Kamus
    
    //Algo
    if (IsTreeOneElmt(*P)){//X adalah 1" nya elemen
        if (Kiri){
            Left(*P) = AlokNode(Y);
        } else {
            Right(*P) = AlokNode(Y);
        }
    } else {
        if (SearchTree(Left(*P),X)){
            AddDaun(&Left(*P),X,Y,Kiri);
        } else {
            AddDaun(&Right(*P),X,Y,Kiri);
        }
    }
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri(BinTree *P, infotype *X){
    //Kamus
    addrNode temp;
    //Algo
    if (IsTreeOneElmt(*P)){
        *X = Akar(*P);
        temp = *P;
        *P = Nil;
        DealokNode(temp);
    } else {
        if (IsUnerRight(*P)){
            DelDaunTerkiri(&Right(*P),X);
        } else {
            DelDaunTerkiri(&Left(*P),X);
        }
    }
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
void DelDaun(BinTree *P, infotype X){
    //Kamus
    addrNode temp;
    //Algo
    if (! IsTreeEmpty(*P)){
        if (IsTreeOneElmt(*P)){// X adalah 1" nya elemen tree
            if (Akar(*P)==X){ // Pengecekkan if dibutuhkann untuk rekursif
                temp = *P;
                *P = Nil;
                DealokNode(temp);
            }
        } else {
            DelDaun(&Left(*P),X);
            DelDaun(&Right(*P),X);
        }
    }
}
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
List MakeListDaun(BinTree P){
    //Kamus
    //Algo
    if (IsTreeEmpty(P)){
        return Nil;
    } else {
        if (IsTreeOneElmt(P)){
            return Alokasi(Akar(P));
        } else {
            return (Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P))));
        }   
    }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListPreorder(BinTree P){
    //Kamus
    List L;
    //Algo
    if (IsTreeEmpty(P)){
        return (Nil);
    } else {
        L = Alokasi(Akar(P));
        if (L == Nil){
            return Nil;
        }else{
            Next(L) = MakeListPreorder(Left(P));
            return (Concat(L,MakeListPreorder(Right(P))));
        } 
    }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   dengan urutan preorder, jika semua alokasi berhasil.
   Menghasilkan list kosong jika ada alokasi yang gagal. */

List MakeListLevelRecc(BinTree P, int N)
{
	/*Kamus Lokal*/
	int Tl, Tr;
	List LL,LR;

	/*Algoritma*/
	if(N==1){
		return Alokasi(Akar(P));
	} else {
		if(IsUnerLeft(P)){
			return MakeListLevelRecc(Left(P),N-1);
		} else if (IsUnerRight(P)) {
			return MakeListLevelRecc(Right(P),N-1);
		} else {
			Tl = Tinggi(Left(P)); 
            Tr = Tinggi(Right(P));
			if(Tl >= N-1 && Tr >= N-1){
				LL = MakeListLevelRecc(Left(P),N-1);
				LR = MakeListLevelRecc(Right(P),N-1);
				if (!IsEmpty(LL) && !IsEmpty(LR)){
					return Concat(LL,LR);
				} else {
					return Nil;
				}
			} else {
				if (Tl >= N-1) {
					return MakeListLevelRecc(Left(P),N-1);
				} else {
					return MakeListLevelRecc(Right(P), N-1);
				}
			} 
		}
	}
}

List MakeListLevel(BinTree P, int N){
    //Kamus
    List L;
    //Algo I (belum ngerti error di mn)
    // if (IsTreeEmpty(P)){
    //     return Nil;
    // } else {
    //     if (N == 1){
    //         L = Alokasi(Akar(P));
    //         return (L);
    //     } else {
    //         return (Concat(MakeListLevel(Left(P),N-1),MakeListLevel(Right(P),N-1)));
    //     }
    // }
    
    //Algo II Menggunakan MakeListLevelRecc
    if(IsTreeEmpty(P)){
		return Nil;
	} else {
		if(N<=0 || N>Tinggi(P)){
			return Nil;
		} else {
			return MakeListLevelRecc(P,N);
		}
	}
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   yang levelnya=N, jika semua alokasi berhasil.
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */

/* *** Binary  Search  Tree  *** */
//Bagian left memiliki angka lbh kecil, Bagian Kanan memiliki angka lbh bsr 
boolean BSearch(BinTree P, infotype X){
    //Kamus
    
    //Algo
    if (IsTreeEmpty(P)){
        return false;
    } else {
        if (Akar(P)==X){
            return true ;
        }else { // Lebih dari 1 elemen(rekurens)
            if (Akar(P) > X){
                return BSearch(Left(P),X);
            } else {//Akar(P) < X
                return BSearch(Right(P),X);
            }
        }
    }

}
/* Mengirimkan true jika ada node dari P yang bernilai X */

void InsSearch(BinTree *P, infotype X){
    //Kamus
    
    //Algo
    if (IsTreeEmpty(*P)){
        MakeTree(X,Nil,Nil,P);
    } else {
        if (X < Akar(*P)){
            InsSearch(&Left(*P),X);
        } else { // X> Akar(P)
            InsSearch(&Right(*P),X);
        }
    }
}   
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */

addrNode minValueNode(BinTree P){//Mencari nilai minimal yang terletak pada daun paling kiri
    addrNode current = P;
    while (Left(current)!= Nil){
        current = Left(current);
    }
    return current;
}

BinTree DelBFunc(BinTree P, infotype X){
    //Kamus
    addrNode temp;
    //Algo
    if (IsTreeEmpty(P)){
        return Nil;
    }
    if (X<Akar(P)){
        Left(P)  = DelBFunc(Left(P),X);
    } else if (X>Akar(P)){
        Right(P) = DelBFunc(Right(P),X);
    } else {//Akar(P) == X
        if (Left(P)==Nil){
            temp = Right(P);
            DealokNode(P);
            return temp;
        }else if (Right(P)==Nil){
            temp = Left(P);
            DealokNode(P);
            return temp;
        } else{//isBiner(q)
            temp = minValueNode(Right(P));
            Akar(P) = Akar(temp);
            Right(P) = DelBFunc(Right(P),Akar(temp));
        }
    }
    return P;
}

void DelBtree(BinTree *P, infotype X){
    *P = DelBFunc(*P,X);
}
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */