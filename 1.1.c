#include<stdio.h>
#define maxVnum 1000
#define maxWg 999
int edge[maxVnum][maxVnum]

void Create(int Vnum, int Enum){
	int u, v, e, i;
	for(i = 1; i <= Vnum; i++){
		for(j = 1; j <= Vnum; j++)
			edge[i][j] = maxWg;
	}
	for(i = 1; i <= Enum; i++){
		scanf("%d %d %d", &u, &v, &e);
		edge[u][v] = e;
		edge[v][u] = e;
	}
}

void Prim(int Vnum, int start){
	int lowcost[maxVnum];
	int visited[maxVnum];
	int i, j;
	for(i = 1; i <= Vnum; i++){
		lowcost[i] = edge[start][i];
		visited[i] = -1;
	}
	visited[start] = 1;
	printf("%d\t%d\n", start, 0);
	for(i = 1; i <= Vnum - 1; i++){
		int next = 0;
		int min = maxWg;
		for(j = 0; j <= Vnum; j++){
			if(lowcost[j] < min && visited[j] == -1){
				min = lowcost[j];
				next = j;
			}
		}
		visited[next] = 1;
		printf("%d\t%d\n", next, min);
		for(j = 1; j <= Vnum; j++){
			if(edge[next][j] < lowcost[j])
				lowcost[j] = edge[next][j];
		}
	}
}

int main(){
	int Vnum, Enum;
	int start;
	scanf("%d %d", &Vnum, &Enum);
	Create(Vnum, Enum);
	while(scanf("%d", &start)){
		if(start == -1)
			break;
		Prim(Vnum, start);
		printf("\n");
	}
}