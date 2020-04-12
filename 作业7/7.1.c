#include<stdio.h>
int F[5][10];//向前i个项目投资j万元的最大收益
int X[5][10];//投资j万元最大收益时投资项目i的钱的数量
int f[5][6] = { {0,0,0,0,0,0},
				{0,11,12,13,14,15},
				{0,0,5,10,15,20}, 
				{0,2,10,30,32,40},
				{0,20,21,22,23,24}};
int main() {
	int m;
	printf("请输入投资的金额（万元）:");
	scanf_s("%d", &m);
	for (int i = 0; i < 5; i++) {
		F[i][0] = 0;
	}
	for (int i = 0; i <= m; i++) {
		F[1][i] = f[1][i];
		X[1][i] = i;
	}

	for (int i = 2; i <= 4; i++) {
		for (int j = 1; j <= m; j++) {
			F[i][j] = 0;
			int t;
			for (int k = 0; k <= j; k++) {
				t = f[i][k] + F[i - 1][j - k];
				if (t > F[i][j]) {
					F[i][j] = t;
					X[i][j] = k;
				}
			}
		}
	}

	int sum = 0;
	int invest;
	for (int i = 4; i >= 1; i--) {
		int invest = X[i][m - sum];
		printf("第%d个项目投资%d万元\n", i, invest);
		sum += invest;
	}
}
