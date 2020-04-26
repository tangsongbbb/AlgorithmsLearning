#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define EQUAL   1
#define UP      2
#define LEFT    3

void LCS(char* str1, char* str2, int** char1, int** char2) {
	int m = strlen(str1);
	int n = strlen(str2);
	int i, j;
	for (i = 0; i <= m; i++) {
		char1[i][0] = 0;
	}
	for (j = 0; j <= n; j++) {
		char1[0][j] = 0;
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				char1[i][j] = char1[i - 1][j - 1] + 1;
				char2[i][j] = EQUAL;
			}
			else if (char1[i - 1][j] >= char1[i][j - 1]) {
				char1[i][j] = char1[i - 1][j];
				char2[i][j] = UP;
			}
			else {
				char1[i][j] = char1[i][j - 1];
				char2[i][j] = LEFT;
			}
		}
	}
}

void FindLCS(char* str, int** b, int i, int j) {
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == EQUAL) {
		FindLCS(str, b, i - 1, j - 1);
		printf("%c ", str[i - 1]);
	}
	else if (b[i][j] == UP)
		FindLCS(str, b, i - 1, j);
	else
		FindLCS(str, b, i, j - 1);

}

void PrintLCS(char* str1, char* str2) {
	int i, j;
	int len1 = strlen(str1), len2 = strlen(str2);
	int** c = (int**)malloc(sizeof(int*) * (len1 + 1));
	int** b = (int**)malloc(sizeof(int*) * (len1 + 1));
	for (i = 0; i <= len1; i++) {
		c[i] = (int*)malloc(sizeof(int) * (len2 + 1));
		b[i] = (int*)malloc(sizeof(int) * (len2 + 1));
	}
	for (i = 0; i <= len1; i++)
		for (j = 0; j <= len2; j++) {
			c[i][j] = 0;
			b[i][j] = 0;
		}
	LCS(str1, str2, c, b);
	printf("The LCS is: ");
	FindLCS(str1, b, len1, len2);
	printf("\n");

	for (i = 0; i <= len1; i++) {
		free(c[i]);
		free(b[i]);
	}
	free(c);
	free(b);
}

int main(int* argc, int* argv[]) {
	char X[50], Y[50];
	int len;
	printf("please enter your characters1:");
	scanf_s("%s", X, 50);
	printf("please enter your characters2:");
	scanf_s("%s", Y, 50);
	PrintLCS(X, Y);
}
