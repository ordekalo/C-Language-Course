#include "func.h"

int multDiv(float num1, float num2, float* pMult, float* pDiv){
	*pMult = num1 * num2;
	if( num2 == 0){
		return 0;
	}
	*pDiv = num1 / num2;
	return 0;
}

void changeChar(char* pChar){
	if( (*pChar >= '0') && (*pChar <= '9'))
		*pChar = 'D';
	else if( (*pChar >= 'a') && (*pChar <= 'z'))
                *pChar = 'S';
	else if( (*pChar >= 'A') && (*pChar <= 'Z'))
                *pChar = 'C';
	else
		*pChar = '0';
}

int reversePositive(int* num){
	if(*num>0){
		int reversed = 0;
		while(*num != 0){
			int digit = *num % 10;
			reversed = reversed * 10 + digit;
			*num /= 10;
		}
		*num = reversed;
		return 1;
	}
	else{
		return 0;
	}
}

void arraySumAndEvenCount(const int arr[], int size, int* sum, int* evens){
	*sum = 0;
	*evens = 0;
	for(int i = 0; i < size; i++){
		if(arr[i] % 2 == 0){
			(*evens)++;
		}
		*sum+=arr[i];
	}
}

void nDivAndEq(const int arr[], int size, int n, int* pDivC, int* pEqC){
	*pEqC = 0;
	*pDivC = 0;
	for(int i = 0; i < size; i++){
		if(arr[i] % n == 0){
			(*pDivC)++;
		}
		if(numSum(arr[i]) == n){
			(*pEqC)++;
		}
	}
}

int numSum(int num){
	int sum = 0;
	while(num != 0){
		int digit = num % 10;
                sum += digit;
                num /= 10;
	}
	return sum;
}
