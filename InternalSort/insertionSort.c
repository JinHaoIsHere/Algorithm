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
 * Straight Insertion Sort is the easiest one
 * regard n numbers in the front of the array as sorted ones(started from 1)
 * store the num and then compare the num with the previous one, then move it step by step
 */
void InsertionSort(int * data, int length){
    int i;
    for(i=1; i<length; i++){
        if(data[i] < data[i-1]){
            int j= i-1;
     	    int tmp = data[i];
            while(tmp < data[j] && j>=0){   //pay attention to the boundary
                data[j+1] = data[j];
                j--;
            }
            data[j+1] = tmp;
        }
        printf("Pass %d: ",i);
        Print(data, 10);                        //print the result after per pass
    }
}




int main(){
	int data[] = {40, 20, 300, 19, 30, 44, 66, 1, -3, -100};
	printf("before: ");
	Print(data,10);
	InsertionSort(data, 10);
}

