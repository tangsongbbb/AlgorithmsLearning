#include<stdio.h>
#define MAX 9999;
void MatrixChain(int p[], int n, int m[][100], int s[][100]) {
	for (int i = 1; i < n; i++) {
		m[i][i] = 0;
	}
	for (int l = 2; l < n; l++) {
		for (int i = 1; i < n - l + 1; i++) {
			int j = i + l - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i; k <= j - 1; k++) {
				int tmp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (tmp < m[i][j]) {
					m[i][j] = tmp;
					s[i][j] = k;
				}
			}
		}
	}
}

void PrintOrder(int s[][100], int i, int j) {
	if (i == j)
		printf("A%d", i);
	else {
		printf("(");
		PrintOrder(s, i, s[i][j]);
		PrintOrder(s, s[i][j] + 1, j);
		printf(")");
	}
}

int main() {
	int p[100];
	int m[100][100], s[100][100];
	int n;
	printf("请输入向量p中 !元素! 的个数:");
	scanf_s("%d", &n);
	printf("请输入向量p的元素:\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &p[i]);
	}
	MatrixChain(p, n, m, s);
	PrintOrder(s, 1, n - 1);
}
