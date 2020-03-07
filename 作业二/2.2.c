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
int path[MAX_NUM];

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
		if (D[start][i] != MAX_NUM)
			path[i] = start;
		else
			path[i] = 0;
	}
	for (i = 1; i <= Vnum; i++) {
		dis[i] = D[start][i];
	}
	visted[start] = 1;
	path[start] = 0;
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
			if (!visted[k] && D[flag][k] + dis[flag] < dis[k]) {
				dis[k] = D[flag][k] + dis[flag];
				path[k] = flag;
			}
		}
		if (flag == end)
			break;
	}
}

int main(){
	int Vnum, Enum;
	int start, end;
	int i, j, t[MAX_NUM];
	scanf_s("%d %d", &Vnum, &Enum);
	Create(Vnum, Enum);
	scanf_s("%d %d", &start, &end);
	Dijkstra(Vnum, start, end);
	j = 1;
	t[0] = end;
	for (i = end; path[i] != 0; i = path[i]) {
		t[j] = path[i];
		j++;
	}
	for (i = j - 1; i >= 0; i--) {
		printf("%d", t[i]);
		if (i != 0)
			printf("-->");
		else
			printf("\n");
	}
}
