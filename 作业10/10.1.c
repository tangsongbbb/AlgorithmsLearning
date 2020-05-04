#include<stdio.h>
typedef struct activity {
	int start;
	int finish;
	bool choose;
};
int main() {
	int n, i, j, t;
	activity A[1000];
	printf("请输入活动数量：");
	scanf_s("%d", &n);
	printf("请按格式输入每个活动的开始和结束时间：\n");
	printf("例：1 5\n");
	for (i = 0; i < n; i++) {
		scanf_s("%d %d", &A[i].start, &A[i].finish);
		A[i].choose = false;
	}
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (A[i].finish > A[j].finish) {
				t = A[i].finish;
				A[i].finish = A[j].finish;
				A[j].finish = t;

				t = A[i].start;
				A[i].start = A[j].start;
				A[j].start = t;
			}
		}
	}
	t = 0;
	for (i = 0; i < n; i++) {
		if (A[i].start >= t) {
			A[i].choose = true;
			t = A[i].finish;
		}
	}
	printf("被选中的活动的起止时间如下：\n");
	for (i = 0; i < n; i++) {
		if (A[i].choose)
			printf("%d %d\n", A[i].start, A[i].finish);
	}
}
