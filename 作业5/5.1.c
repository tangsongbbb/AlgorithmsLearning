#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct point {
	int x;
	int y;
};

double Distance(point a, point b) {
	double dist;
	dist = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	return dist;
}

int cmp(const void* a, const void* b) {
	struct point ac = *(struct point*)a;
	struct point bd = *(struct point*)b;
	if (ac.x != bd.x)
		return ac.x - bd.x;
	else return ac.y - bd.y;
}

double ClosestPoint(point p[], int low, int high) {
	int i, j, mid;
	double min_dist = 9999.0;
	if (high == low) {
		return 9999;
	}
	else if (high - low == 1) {
		min_dist = Distance(p[low], p[high]);
		return min_dist;
	}
	mid = (high + low) / 2;
	double dist1, dist2, dist3;
	dist1 = ClosestPoint(p, low, mid);
	dist2 = ClosestPoint(p, mid + 1, high);
	min_dist = dist1 > dist2 ? dist2 : dist1;
	dist3 = 9999;
	for (i = low; i <= high; i++) {
		for (j = low; j <= high; j++) {
			if ((p[i].x <= p[mid].x && p[i].x >= p[mid].x - min_dist) && (p[j].x >= p[mid].x
      && p[j].x <= p[mid].x + min_dist) && i != j) {
				if (Distance(p[i], p[j]) < dist3)
					dist3 = Distance(p[i], p[j]);
			}
		}
	}
	min_dist = min_dist > dist3 ? dist3 : min_dist;
	return min_dist;
}

int main() {
	int n;
	double min_dist;
	point p[1000];
	printf("请输入点的个数：");
	scanf_s("%d", &n);
	printf("请按此格式输入点集：x y\n");
	int i, x, y;
	for (i = 0; i < n; i++) {
		scanf_s("%d %d", &x, &y);
		p[i].x = x;
		p[i].y = y;
	}
	qsort(p, n, sizeof(p[0]), cmp);
	min_dist = ClosestPoint(p, 0, n - 1);
	printf("最近点对的距离是%f\n", min_dist);
}
