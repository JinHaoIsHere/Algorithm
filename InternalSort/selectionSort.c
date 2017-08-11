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
 *  selection sort: choose the smaillest(or biggest) number in the array 
 *  and switch it to the top of the sorted part.
 *  untill whole array is sorted
 *  very simple
 */

void SelectionSort(int * data, int length){
	int i;
	for(i=0; i<length-1; i++){			//length-1 because if n-1 numbers in the front are sorted, the last one must be sorted
		int j;
		int index = i;
		int tmp;
		for(j=i+1; j<length; j++){
			if(data[j] < data[index]){ //data of index is the smallest one
				index = j;
			}
		}
		if(i!=index){
			tmp = data[index];
			data[index] =data[i];
			data[i] = tmp;
		}
		Print(data,10);
	}
}

/*
 *  double selection sort: choose the smaillest and biggest number in the array 
 *  higher efficiency
 */
void DoubleSelectionSort(int * data, int length){
	int i;
	for(i=0; i<length/2; i++){
		int j;
		int max=length-i-1;
		int min=i;
		int tmp;
		for(j=i; j<length-i; j++){	//select the max and min in a single pass
			if(data[max] < data[j])
				max=j;
			if(data[min] > data[j])
				min=j;
		}
		if(i!=min){					//put max and min in correct place
			tmp = data[min];
			data[min] =data[i];
			data[i] = tmp;
		}
		if(length-i-1 != max && i != max){ //i != max forbidden the following condition: 3-2   ==>   2-3    ==>    3-2
			tmp = data[max];
			data[max] =data[length-i-1];
			data[length-i-1] = tmp;
		}
		Print(data,10);
	}
}



int main(){
	int data[] = {40, 20, 300, 19, 30, 44, 66, 1, -3, -100};
	printf("before: ");
	Print(data,10);
	DoubleSelectionSort(data, 10);
}

