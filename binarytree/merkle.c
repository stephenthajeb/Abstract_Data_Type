//Stephen Thajeb 13518150
//16 November 2019

#include <stdio.h>
#include "bintree.h"
#include "listrek.h"
#include <math.h>

BinTree MakeMerkle(int n){
	infotype X,Y;
	BinTree B;
	
	B = Tree(0,Nil,Nil);
	if (n==2){
		scanf("%d",&X);
		Left(B) = Tree(X,Nil,Nil);
		scanf("%d",&Y);
		Right(B) = Tree(Y,Nil,Nil);
	} else {
		Left(B) = MakeMerkle(n/2); //dibagi rata antara kiri dengan kanan
		Right(B) = MakeMerkle(n/2);
	}
	Akar(B) = Akar(Left(B)) + Akar(Right(B));
	return B;
}

int main (){
	int n;
	double temp;
	BinTree Hsl;

	// scanf("%d",&n);
	// if (n % 2== 1 || n<1){
	// 	printf("Jumlah masukan tidak sesuai\n");
	// } else {
	// 	Hsl = MakeMerkle(n);
	// 	PrintTree(Hsl,2);
	// }

	scanf("%d",&n);
	temp = log(n)/log(2);
	if (temp != floorf(temp)|| temp < 1){
		printf("Jumlah masukan tidak sesuai\n");
	}else{
		Hsl = MakeMerkle(n);
		PrintTree(Hsl,2);
	}

	return 0;
}