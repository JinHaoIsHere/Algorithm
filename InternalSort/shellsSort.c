#include <stdio.h>
#include <stdlib.h>

void Print(int * data, int length){
	int i=0;
	for(i=0;i<length;i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
/*
 * this algorithm is an advanced version of insertion sort
 * with better performance, (exchanged times for example data: shell: 21 / insertion: 40)
 * allow data to exchange with bigger step
 */

void ShellInsertSort(int * data, int length, int dk){
	int i;
	for(i=dk; i<length; i++){
		if(data[i]<data[i-dk]){
			int j = i-dk;
			int tmp = data[i];
			while(tmp<data[j] && j>=0){
				data[j+dk] = data[j];
				j -= dk;
			}
			data[j+dk] = tmp;
		}
		Print(data,10);
	}
}


void ShellsSort(int * data, int length){	
	int dk = length/2;
	while(dk>=1){
		printf("--\n");
		ShellInsertSort(data, length, dk);
		dk = dk/2;
	}
}


int main(){
	int data[] = {40, 20, 300, 19, 30, 44, 66, 1, -3, -100};
	printf("before: ");
	Print(data,10);
	ShellsSort(data, 10);
}

