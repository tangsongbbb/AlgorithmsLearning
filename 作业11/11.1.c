#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define n 26
#define m 2*n-1
typedef struct {
	double weight;
	int parent, lchild, rchild;
}HTNode;
typedef HTNode HuffmanTree[m];

typedef struct {
	int id; 
	double weight; 
}temp;

typedef struct {
	char ch;
	char bits[n + 1];
}CodeNode;
typedef CodeNode HuffmanCode[n];

void InitHuffmanTree(HuffmanTree T, int n1) {
	int m1 = 2 * n1 - 1;
	for (int i = 0; i < m1; i++) {
		T[i].lchild = -1;
		T[i].rchild = -1;
		T[i].parent = -1;
		T[i].weight = 0;
	}
}

void InputWeight(HuffmanTree T, int n1) {
	for (int i = 0; i < n1; i++) {
		double x;
		scanf_s("%lf", &x);
		T[i].weight = x;
	}
}

bool cmp(temp a, temp b) {
	return a.weight < b.weight;
}

void SelectMin(HuffmanTree T, int k, int* p1, int* p2) {
	temp x[m];
	int i, j;
	for (i = 0, j = 0; i <= k; i++) {
		if (T[i].parent == -1) {
			x[j].id = i;
			x[j].weight = T[i].weight;
			j++;
		}
	}
	sort(x, x + j, cmp);
	*p1 = x[0].id;
	*p2 = x[1].id;
}

void CreateHuffmanTree(HuffmanTree T, int n1) {
	int i, p1, p2;
	InitHuffmanTree(T, n1);
	InputWeight(T, n1);
	int m1 = 2 * n1 - 1;
	for (i = n1; i < m1; i++) {
		SelectMin(T, i - 1, &p1, &p2);
		T[p1].parent = T[p2].parent = i;
		T[i].lchild = p1;
		T[i].rchild = p2;
		T[i].weight = T[p1].weight + T[p2].weight;
	}
}

void CharSetHuffmanEncoding(HuffmanTree T, HuffmanCode H, int n1) {
	int c, p;
	char cd[n + 1];
	int start;
	cd[n1] = '\0';
	getchar();
	for (int i = 0; i < n1; i++) {
		H[i].ch = getchar();
		start = n1;
		c = i;
		while ((p = T[c].parent) >= 0) {
			if (T[p].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
			c = p;
		}
		strcpy_s(H[i].bits, &cd[start]);
	}
}

int main() {
	HuffmanTree T;
	HuffmanCode H;
	int n1;
	printf("请输入字符总数（小于26)：");
	scanf_s("%d", &n1);
	printf("请输入每个字符的出现频率（以空格分隔）：");
	CreateHuffmanTree(T, n1);
	printf("请输入字符（以连续字符串形式输入，如：abcd）：");
	CharSetHuffmanEncoding(T, H, n1);
	printf("哈夫曼编码：\n");
	for (int i = 0; i < n1; i++) {
		printf("id:%d   ch:%c  code:%s\n", i, H[i].ch, H[i].bits);
	}
}
