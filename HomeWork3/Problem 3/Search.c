#include <stdio.h> 
#include <stdlib.h>

int Search(int array[], int min, int max) {
	if(max >= min) {
		int middle = (min + max) / 2;
		if(array[middle] == middle) {
			return middle;
		} else if(array[middle] < middle) {
			return Search(array, middle+1, max);
		} else {
			return Search(array, min, middle-1);
		}
	}
	return -1;
}
int main() 
{ 	
	int arr []= {-1, -2, 3, 5, 6, 7}; 
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = Search(arr, 0, size);
	if(result == -1) {
		printf("There is no such index value\n");
	} else {
		printf("Result = Numbers[%d] = %d\n", result, result);
	}
	return 0; 
} 