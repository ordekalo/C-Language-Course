#include <stdio.h>
#include "functionsLab1.h"

void printHello(){
	printf("Hello World\n");
}

void printTriangle(int base){
	for(int i = 0; i<=base; i++){
		for(int j = 0; j<=i; j++){
			printf("*");
		}
		printf("\n");
	}
}
