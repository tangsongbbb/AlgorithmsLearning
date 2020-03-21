#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Merge(int d[], int left, int mid, int right, int* t) {
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (d[i] < d[j])
			t[k++] = d[i++];
		else
			t[k++] = d[j++];
	}
	while (i <= mid) {
		t[k++] = d[i++];
	}
	while (j <= right) {
		t[k++] = d[j++];
	}
	memcpy(d + left, t + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int d[], int left, int right, int* t) {
	int mid = 0;
	if (left < right) {
		mid = left + (right - left) / 2;
		MergeSort(d, left, mid, t);
		MergeSort(d, mid + 1, right, t);
		Merge(d, left, mid, right, t);
	}
}

int main() {
	int n, i;
	int data[100];
	printf("please input the amount of number(1—100):");
	scanf_s("%d", &n);
	int* t = (int*)malloc(sizeof(int) * n);
	printf("please input the numbers:\n");
	for (i = 0; i < n; i++) {
		scanf_s("%d", &data[i]);
	}
	MergeSort(data, 0, n - 1, t);
	for (i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
}
