#include <stdio.h>
#include <stdlib.h>

void BubbleSort1(int * data, int length){
	int i=0, j=0;
	int tmp;
	int counter=0;
	for (i=0;i<length;i++){
		for(j=0;j<length;j++){
			if(data[i] < data[j]){
				counter++;
				tmp = data[j];
				data[j] = data[i];
				data[i] = tmp;
			}
		}
	} 
	printf("exchange %d times\n", counter);
}
/*
 * almost same as the first one, as well as the performace
 * the principle of the second one could be easier to be perceived
 * contrary comparison sign
 *
 */
void BubbleSort2(int * data, int length){
	int i=0, j=0;
	int tmp;
	int counter=0;
	for (i=0;i<length;i++){
		for(j=0;j<length-1-i;j++){
			if(data[j] > data[j+1]){
				counter++;
				tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	} 
	printf("exchange %d times\n", counter);
}

/*
 * set a flag, if the array is sorted the the flag will be 0 and the program is ended
 */
void BubbleSort3(int * data, int length){
	int i=0, j=0;
	int tmp;
	int flag;
	int counter=0;
	for (i=0;i<length;i++){
		flag = 0;
		for(j=0;j<length-1-i;j++){
			if(data[j] > data[j+1]){
				flag=1;
				counter++;
				tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
		if(flag==0){
			break;
		}
	} 
	printf("exchange %d times\n", counter);
}


void Print(int * data, int length){
	int i=0;
	for(i=0;i<length;i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}

int main(){
	printf("Hello world\n");
	int data[] = {40, 20, 300, 19, 30, 44, 66, 01, -3, -100};
	printf("before:\n");
	Print(data,10);
	BubbleSort3(data, 10);
	printf("after:\n");
	Print(data,10);
}

