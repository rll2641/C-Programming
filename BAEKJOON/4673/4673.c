#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void ret(int* arr, int num) {
	int sum = num;
	while (num) {
		sum += num % 10;
		num /= 10;
	}
	if (sum < 10000) {
		arr[sum] = 1;
		ret(arr, sum);
	}
}
 
int main() {
	int i;
	int* arr= (int*)malloc(sizeof(int) * 10000);
	memset(arr, 0, sizeof(int) * 10000);
	
	for (i = 1; i < 10000; i++) {
		if (!arr[i]) {
			ret(arr, i);
			printf("%d\n", i);
		}
	}
	
	free(arr);
	return 0;
}