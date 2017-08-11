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

/*
 * use recursion to adjust the array
 * this algorithm has a good performance (O(nlog2n)) but could be very bad if the array is almosted sorted(O(n^2))
 */
void QuickSort(int * data, int start, int end){		
	if(start < end){
		//first choose the first one as key and partation the array into two parts, so that
		//everyone in the first part are less than key and everyone in the second part are bigger than key
		int i=start, j=end;
		int key = data[start];
		int tmp;
		while(i<j){
			while(i<j && data[j]>=key)
				j--;
			if(i!=j){
				tmp = data[i];
				data[i]=data[j];
				data[j]=tmp;
			}
			while(i<j && data[i]<=key)
				i++;
			if(i!=j){
				tmp = data[i];
				data[i]=data[j];
				data[j]=tmp;
			}
		}
		Print(data, LEN);
		//then adjust the two parts separately by recursion
		QuickSort(data, start, i-1);
		QuickSort(data, i+1, end);
	}
}

int main(){
	int data[] = {40, 20, 300, 19, 30, 44, 66, 1, -3, -100};
	printf("before: \n");
	Print(data,LEN);
	QuickSort(data, 0, LEN-1);
}

