/*
input:
8 11
1 2 1
2 4 2
4 3 1
3 1 2
5 4 2
4 6 8
6 5 2
5 7 2
7 8 3
8 6 2
7 6 3
1 8
*/
#include<stdio.h>
#define MAX_NUM 999
int D[MAX_NUM][MAX_NUM];
int dis[MAX_NUM];
int visted[MAX_NUM];

void Create(int Vnum, int Enum) {
	int i, j;
	int u, v, e;
	for (i = 1; i <= Vnum; i++) {
		visted[i] = 0;
		for (j = 1; j <= Vnum;  j++) {
			if (i == j)
				D[i][j] = 0;
			else
				D[i][j] = MAX_NUM;
		}
	}
	for (i = 1; i <= Enum; i++) {
		scanf_s("%d %d %d", &u, &v, &e);
		D[u][v] = e;
	}
}

void Dijkstra(int Vnum, int start, int end) {
	int i, j, k;
	int min, flag;
	for (i = 1; i <= Vnum; i++) {
		dis[i] = D[start][i];
	}
	visted[start] = 1;
	for (i = 0; i <= Vnum; i++) {
		min = MAX_NUM;
		for (j = 1; j <= Vnum; j++) {
			if (!visted[j] && dis[j] < min) {
				min = dis[j];
				flag = j;
			}
		}
		visted[flag] = 1;
		for (k = 1; k <= Vnum; k++) {
			if (D[flag][k] + dis[flag] < dis[k])
				dis[k] = D[flag][k] + dis[flag];
		}
	}
	printf("%d\n", dis[end]);
}

int main(){
	int Vnum, Enum;
	scanf_s("%d %d", &Vnum, &Enum);
	Create(Vnum, Enum);
	int start, end;
	scanf_s("%d %d", &start, &end);
	Dijkstra(Vnum, start, end);
}
