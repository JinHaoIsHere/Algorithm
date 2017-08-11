#include <stdio.h>
#include <stdlib.h>
#define LEN 10

void Print(int * data, int length){
	int i=0;
	for(i=0;i<length;i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}

//merge two arrays(data[i,....m], data[m+1, ... ,n]) to an array(data[i....n])
void Merge(int * data, int * tmpData, int i, int m, int n){
	int p=i, q=m+1;
	int k=i;			//for tmpData
	for(; p<=m && q<=n; k++){
		if(data[p]<data[q])
			tmpData[k] = data[p++];
		else
			tmpData[k] = data[q++];
	}
	while(p<=m) 	//handle the rest of two arrays
		tmpData[k++] = data[p++];
	while(q<=n)
		tmpData[k++] = data[q++];
}

/*
 * we can regard a single element as a sorted array
 * then we can merge two single arrays into a bigger one
 * we can gradually increase the size of sorted arrays (1, 2, 4, 8, 16)
 * until the size is bigger than length or the origin array
 * we get a sorted array
 * the performance of the algorithm is always O(nlogn)
 */
void MergeSort(int * data, int length){		
	int tmpData[LEN];
	int size = 1;
	int * tmp;
	while(size < length){	
		int i=0;
		while(i+size*2 < length){
			Merge(data, tmpData, i, i+size-1, i+size*2-1);
			i+=size*2;
		}
		if(i+size < length){
			Merge(data, tmpData, i, i+size-1, length-1);
		}
		Print(tmpData,LEN);
		//move the data
		for(i=0; i<length; i++){
			data[i] = tmpData[i];
		}
		size*=2;
	}
}

int main(){
	int data[] = {40, 20, 300, 19, 30, 44, 66, 1, -3, -100};
	printf("before: \n");
	Print(data,LEN);
	MergeSort(data, LEN);
}

