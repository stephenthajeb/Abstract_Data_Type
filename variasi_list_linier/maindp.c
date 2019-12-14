// #include "listsirkuler.h"
#include "listdp.h"
#include <stdio.h>


address SearchPrec (List L, infotype X) {
	/* Kamus Lokal */
	address P;
	boolean Found;

	/* Algoritma */
	P = First(L);
	Found = false;
	if (P == Nil) {
		return Nil;
	} else {
		while ((Next(P) != Nil) && (!Found)) {
			if (X == Info(Next(P))) {
				Found = true;
			} else {
				P = Next(P);
			}
		}
	}
	if (Next(P) == Nil) {
		return Nil;
	} else {
		return P;
	}
}
void DelAll (List *L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	while (!IsListEmpty(*L)) {
		DelFirst(L,&P);
		Dealokasi(&P);
	}
}

void InversList (List *L) {
	/* Kamus Lokal */
	address P, Temp;

	/* Algoritma */
	P = First(*L);
	if (!IsListEmpty(*L)) {
		Temp = First(*L);
		First(*L) = Last(*L);
		Last(*L) = Temp;
	}
	while (P != Nil) {
		Temp = Next(P);
		Next(P) = Prev(P);
		Prev(P) = Temp;
		P = Temp;
	}
}

List FInversList (List L) {
	/* Kamus Lokal */
	address P, Temp;
	List L1;
	boolean fail;

	/* Algoritma */
	fail = false;
	P = First(L);
	CreateList(&L1);
	while ((P != Nil) && (!fail)) {
		Temp = Alokasi(Info(P));
		if (Temp != Nil) {
			InsertFirst(&L1,Temp);
			P = Next(P);
		} else {
			DelAll(&L1);
			fail = true;
		}
	}
	return L1;
}

List FCopyList (List L) {
	/* Kamus Lokal */
	address P, Temp;
	List L1;
	boolean fail;

	/* Algoritma */
	fail = false;
	CreateList(&L1);
	P = First(L);
	while ((P != Nil) && (!fail)) {
		Temp = Alokasi(Info(P));
		if (Temp != Nil) {
			InsertLast(&L1,Temp);
			P = Next(P);
		} else {
			fail = true;
			DelAll(&L1);
		}
	}
	return L1;
}

void CpAlokList (List Lin, List *Lout) {
	/* Kamus Lokal */
	address P, Pt;
	boolean gagal;

	/* Algoritma */
	CreateList(Lout);
	gagal = false;
	P = First(Lin);
	while ((P != Nil)&&(!gagal)) {
		Pt = Alokasi(Info(P));
		if (Pt != Nil) {
			InsertLast(Lout,Pt);
			P = Next(P);
		} else {
			gagal = true;
			DelAll(Lout);
		}
	}
}

void Konkat (List L1, List L2, List *L3) {
	/* Kamus Lokal */
	address P, Pt;
	boolean gagal;

	/* Algoritma */
	CreateList(L3);
	gagal = false;
	P = First(L1);
	while ((P != Nil)&&(!gagal)) {
		Pt = Alokasi(Info(P));
		if (Pt != Nil) {
			InsertLast(L3,Pt);
			P = Next(P);
		} else {
			gagal = true;
			DelAll(L3);
		}
	}
	if (!gagal) {
		P = First(L2);
		while ((P != Nil)&&(!gagal)) {
			Pt = Alokasi(Info(P));
			if (Pt != Nil) {
				InsertLast(L3,Pt);
				P = Next(P);
			} else {
				gagal = true;
				DelAll(L3);
			}
		}
	}
}

void Konkat1 (List *L1, List *L2, List *L3) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = First(*L1);
	CreateList(L3);
	First(*L3) = First(*L1);
	if (P != Nil) {
		while (Next(P) != Nil) {
			P = Next(P);
		}
	}
	Next(P) = First(*L2);
	CreateList(L1);
	CreateList(L2);
}

void PecahList (List *L1, List *L2, List L) {
	/* Kamus Lokal */
	address P, Pt;
	boolean gagal;
	int i, N;

	/* Algoritma */
	CreateList(L1);
	CreateList(L2);
	gagal = false;
	i = 1;
	N = NbElmt(L)/2;
	P = First(L);
	while ((P != Nil) && (!gagal)) {
		Pt = Alokasi(Info(P));
		if (i <= N) {
			if (Pt != Nil) {
				InsertLast(L1,Pt);
				P = Next(P);
				i++;
			} else {
				gagal = true;
				DelAll(L1);
			}
		} else {
			if (Pt != Nil) {
				InsertLast(L2,Pt);
				P = Next(P);
				i++;
			} else {
				gagal = true;
				DelAll(L2);
			}
		}
	}
}


int main(){
    

    return 0;
}