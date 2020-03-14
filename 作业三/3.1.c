#include<stdio.h>
int main() {
	int data[11] = {NULL,5,7,10,15,16,19,24,26,27,34};
	int i, key;
	int flag = 0;
	printf("27,15,10,7,5,19,16,24,34,26\n");
	printf("please enter the number to search:");
	scanf_s("%d", &key);
	for (i = 1; i < 11; i++) {
		if (data[i] == key) {
			printf("j = %d", i);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("j=0");
}
