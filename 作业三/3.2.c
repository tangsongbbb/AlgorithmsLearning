#include<stdio.h>
int main() {
	int data[11] = {NULL,5,7,10,15,16,19,24,26,27,34};
	int key;
	int flag = 0;
	int low = 1, high = 10, mid;
	printf("27,15,10,7,5,19,16,24,34,26\n");
	printf("please enter the number to search:");
	scanf_s("%d", &key);
	while (low <= high) {
		mid = (low + high) / 2;
		if (key < data[mid])
			high = mid - 1;
		else if (key > data[mid])
			low = mid + 1;
		else {
			printf("j = %d", mid);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("j=0");
}
