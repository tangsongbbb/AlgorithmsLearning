/*
input:
4 8
1 2 2
2 3 3
1 3 6
3 1 7
3 4 1
4 3 12
1 4 4
4 1 5
*/
#include<stdio.h>
#define MAX_NUM 999
int D[MAX_NUM][MAX_NUM];

void Create(int Vnum, int Enum) {
	int i, j;
	int u, v, e;
	for (i = 1; i <= Vnum; i++) {
		for (j = 1; j <= Vnum;  j++) {
			D[i][j] = MAX_NUM;
			if (i == j)
				D[i][j] = 0;
		}
	}
	for (i = 1; i <= Enum; i++) {
		scanf_s("%d %d %d", &u, &v, &e);
		D[u][v] = e;
	}
}

void Floyd(int Vnum) {
	int i, j, k;
	for (k = 1; k <= Vnum; k++) {
		for (i = 1; i <= Vnum; i++) {
			for (j = 1; j <= Vnum; j++) {
				if (D[i][j] > D[i][k] + D[k][j])
					D[i][j] = D[i][k] + D[k][j];
			}
		}
	}
}

void Show(int Vnum) {
	int i, j;
	for (i = 1; i <= Vnum; i++) {
		for (j = 1; j < Vnum; j++) {
			printf("%d\t", D[i][j]);
		}
		printf("%d\n", D[i][j]);
	}
}

int main(){
	int Vnum, Enum;
	scanf_s("%d %d", &Vnum, &Enum);
	Create(Vnum, Enum);
	Floyd(Vnum);
	Show(Vnum);
}
