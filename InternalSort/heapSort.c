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



void adjustHeap(int * data, int length, int h){		//adjust the array to a heap
	int child = 2*h+1;
	if(child+1<length && data[child+1]<data[child])
		child=child+1;
	if(child<length && data[h] > data[child]){
		//time to switch
		int tmp = data[h];
		data[h] = data[child];
		data[child] = tmp;
		
		adjustHeap(data, length, child);
	}
}

void buildHeap(int * data, int length){		//build an unsorted array to a heap
	int i = (length-2)/2;					//parent node of the last node(length-1)

	for(;i>=0; i--){
		
		adjustHeap(data, length, i);	
	}
	
}

/*
 * this algorithm is based on the heap theory
 * this can keep every parent node is smaller than its children nodes(so called small top heap)
 * two important processes are:
 * how to build a heap
 * how to adjust a heap
 */
void HeapSort(int * data, int length){		
	buildHeap(data, length);
	int i;
	for(i=length-1; i>0; i--){
		printf("round %d:\n",i);
		int tmp = data[i];					//put the smallest one to the tail
		data[i]=data[0];
		data[0]=tmp;
		adjustHeap(data, i, 0);
		Print(data, LEN);
	}
	int j;
	for(i=0,j=length-1; i<j; i++,j--){		//reverse the array (if is necessary)
		int tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}
	Print(data, LEN);
}

int main(){
	int data[] = {40, 20, 300, 19, 30, 44, 66, 1, -3, -100};
	//int data[] = {53, 30};
	printf("before: ");
	Print(data,LEN);
	HeapSort(data, LEN);
}

