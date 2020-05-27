#include<iostream>
using namespace std;
int c[100][100]; //邻接矩阵
int color[100];  //每个顶点的颜色 
int ccount=0, m, n;
int Check(int k) {
	for (int i = 1; i <= k; i++) {
		if (c[k][i] == 1 && color[i] == color[k])
			return 0;
	}
	return 1;
}

void GraphColor(int step) {
	if (step == n + 1) {
		for (int i = 1; i <= n; i++)
			printf("%d \n", color[i]);
		ccount++;
		printf("\n");
		return;
	}
	else {
		for (int i = 1; i <= m; i++) {
			color[step] = i;
			if (Check(step) == 1) {
				GraphColor(step + 1);

			}
			color[step] = 0;
		}
	}
}

int main(void) {
	printf("请输入顶点和颜色的数量，以空格间隔:\n");
	scanf_s("%d %d", &n, &m);
	printf("请输入邻接矩阵:\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	printf("着色方案如下:\n");
	GraphColor(1);
	if (ccount == 0)
		printf("NO\n");
	return 0;
}
