#include<stdio.h>
#define maxVnum 1000
#define maxWg 999
int edge[maxVnum][maxVnum];

void Create(int Vnum, int Enum) {
	int u, v, e, i, j;
	for (i = 1; i <= Vnum; i++) {
		for (j = 1; j <= Vnum; j++)
			edge[i][j] = maxWg;
	}
	for (i = 1; i <= Enum; i++) {
		scanf_s("%d %d %d", &u, &v, &e);
		edge[u][v] = e;
		edge[v][u] = e;
	}
}

void Prim(int Vnum, int start) {
	int lowcost[maxVnum];
	int visited[maxVnum];
	int i, j;
	for (i = 1; i <= Vnum; i++) {
		lowcost[i] = edge[start][i];
		visited[i] = -1;
	}
	visited[start] = 1;
	printf("起始点为：\n");
	printf("%d\n", start);
	printf("下一个点及到该点的权重:\n");
	for (i = 1; i <= Vnum - 1; i++) {
		int next = 0;
		int min = maxWg;
		for (j = 0; j <= Vnum; j++) {
			if (lowcost[j] < min && visited[j] == -1) {
				min = lowcost[j];
				next = j;
			}
		}
		visited[next] = 1;
		printf("%d weight:%d\n", next, min);
		for (j = 1; j <= Vnum; j++) {
			if (edge[next][j] < lowcost[j])
				lowcost[j] = edge[next][j];
		}
	}
}

int main() {
	int Vnum, Enum;
	int start;
	scanf_s("%d %d", &Vnum, &Enum);
	Create(Vnum, Enum);
	while (scanf_s("%d", &start)) {
		if (start == -1)
			break;
		Prim(Vnum, start);
		printf("\n");
	}
}
/*
input:
7 12
1 2 2
1 3 4
1 4 1
2 4 3
2 5 10
3 4 2
4 5 7
6 3 5
6 4 8
7 4 4
7 5 6
6 7 1
1
6
-1
*/
