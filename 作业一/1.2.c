#include<stdio.h>
#define maxVnum 1000
#define maxWg 999
int edge[maxVnum][maxVnum];
int parent[maxVnum];

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

int father(int e) {
	if (parent[e] != e)
		return father(parent[e]);
	else
		return e;
}

void Union(int x, int y) {
	parent[father(y)] = father(x);
}

void Kruskal(int Vnum) {
	int i, j, u, v;
	int count = 0;
	for (i = 1; i <= Vnum; i++)
		parent[i] = i;
	while (count != Vnum - 1) {
		int minWg = 999;
		for (i = 1; i <= Vnum; i++) {
			for (j = 1; j <= Vnum; j++) {
				if (edge[i][j] < minWg) {
					u = i;
					v = j;
					minWg = edge[i][j];
				}
			}
		}
		edge[u][v] = maxWg;
		if (father(u) != father(v)) {
			printf("(%d,%d),%d\n", u, v, minWg);
			Union(u, v);
			count++;
		}
	}
}

int main() {
	int Vnum, Enum;
	scanf_s("%d %d", &Vnum, &Enum);
	Create(Vnum, Enum);
	Kruskal(Vnum);
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
*/
