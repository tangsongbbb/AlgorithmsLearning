#include <iostream>
using namespace std;
void insertSort(int R[], int low, int high) {
	int i, j, tmp;
	for (i = low + 1; i <= high; ++i) {
		tmp = R[i];
		j = i - 1;
		while (j >= low && R[j] > tmp) {
			R[j + 1] = R[j];
			--j;
		}
		R[j + 1] = tmp;
	}
}

int FindMid(int R[], int low, int high) {
	if (low == high) {
		return R[low];
	}
	int i, k;
	for (i = low; i + 4 <= high; i += 5) {
		insertSort(R, i, i + 4);
		k = i - low;
		swap(R[low + k / 5], R[i + 2]);
	}
	int n = high - i + 1;
	if (n > 0) {
		insertSort(R, i, high);
		k = i - low;
		swap(R[low + k / 5], R[i + n / 2]);
	}
	k = k / 5;
	if (k == 0) {
		return R[low];
	}
	return FindMid(R, low, low + k);
}

int FindId(int R[], int low, int high, int median) {
	for (int i = low; i <= high; ++i) {
		if (median == R[i]) {
			return i;
		}
	}
	return -1;
}

int Partion(int R[], int low, int high, int index) {
	if (low <= high) {
		swap(R[index], R[low]);
		int tmp = R[low];
		int i = low, j = high;
		while (i != j) {
			while (j > i&& R[j] >= tmp) {
				--j;
			}
			R[i] = R[j];
			while (i < j && R[i] <= tmp) {
				++i;
			}
			R[j] = R[i];
		}
		R[i] = tmp;
		return i;
	}
	return -1;
}

int Select(int R[], int low, int high, int K) {
	int median = FindMid(R, low, high);
	int index = FindId(R, low, high, median);
	int newIndex = Partion(R, low, high, index);
	int rank = newIndex - low + 1;
	if (rank == K) {
		return newIndex;
	}
	else if (rank > K) {
		return Select(R, low, newIndex - 1, K);
	}
	return Select(R, newIndex + 1, high, K - rank);
}
int main() {
	int i, n, k, d[100];
	cout << "Please input the amount:";
	cin >> n;
	cout << "Please input the numbers:" << endl;
	for (i = 0; i < n; i++) {
		cin >> d[i];
	}
	cout << "Please input k:";
	cin >> k;
	int index;
	index = Select(d, 0, n - 1, k);
	cout << "the number is: " << d[index] << endl;
}
