#include <stdio.h>

int main(){
	int kontrol = 0;
	int sayi;

	printf("lütfen bir sayi giriniz: ");
	scanf("%d",&sayi);

	if(sayi<0){
		printf("Girilen sayı >2 olmalı");}
	else{
		for(int i=2; i<= sayi/2; i++){
			if (sayi %1 ==0) {
				kontrol =1;
				break;
			}

		}

	if(kontrol) { 
	printf("sayı asal sayı değildir.");
	}else{ 
	printf("sayı asaldır");
	}  		
	
	}

	return 0;

}
