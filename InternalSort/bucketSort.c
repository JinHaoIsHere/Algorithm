#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10
int LEN;

void Print(int * data, int length){
	int i=0;
	for(i=0;i<length;i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}


void InsertionSort(int * data, int length){
    int i;
    for(i=1; i<length; i++){
        if(data[i] < data[i-1]){
            int j= i-1;
     	    int tmp = data[i];
            while(tmp < data[j] && j>=0){   
                data[j+1] = data[j];
                j--;
            }
            data[j+1] = tmp;
        }          
    }
}

/*
 * we assume that every number is in the range of [0, 100)
 * and we can prepare 10 buckets, first one for [0,10), second one for [10, 20) and so on
 * then we distribute numbers to 10 buckets and then sort numbers in buckets separately
 * good performance, if the numbers are distributed evenly, then the performance could be O(n)
 */
void BucketSort(int * data, int length){		
	int * buckets[BUCKET_SIZE];
	int sizeOfBuckets[BUCKET_SIZE];
	int i;
	for(i=0; i<BUCKET_SIZE; i++){	//initailize the buckets array
		buckets[i] = NULL;
		sizeOfBuckets[i] = 0;
	}
	for(i=0; i<length; i++){
		int target = data[i]/BUCKET_SIZE;
		if(buckets[target] == NULL){
			buckets[target] = (int *)malloc(sizeof(int)*LEN);	//max bucket for ensurance
		}														//here linked list should be better, but it is not convenient for sorting
		buckets[target][sizeOfBuckets[target]++] = data[i];
	}

	for(i=0; i<BUCKET_SIZE; i++){	//sort data in buckets separately
		if(buckets[i]!= NULL)
			InsertionSort(buckets[i], sizeOfBuckets[i]);
	}

/*	//print part
	for(i=0; i<BUCKET_SIZE; i++){
		if(sizeOfBuckets[i] != 0){
			printf("Bucket %d:\n",i);
			int j;
			for(j=0; j<sizeOfBuckets[i]; j++){
				printf("%d ",buckets[i][j]);
			}
			printf("\n");
		}
	}
*/
	int k=0;
	for(i=0; i<BUCKET_SIZE; i++){
		if(buckets[i] != NULL){
			int j=0;
			for(; j<sizeOfBuckets[i]; j++)
				data[k++] = buckets[i][j];
		}
	}
	Print(data, BUCKET_SIZE);
}

int main(){
	int data[] = {40, 20, 33, 19, 30, 44, 66, 1, 3, 99};
	LEN = sizeof(data)/sizeof(int);
	printf("before: \n");
	Print(data,LEN);
	BucketSort(data, LEN);
}

