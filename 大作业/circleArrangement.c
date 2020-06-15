#include <iostream>
#include <cmath>
using namespace std;

template <class Type>
inline void Swap(Type& a, Type& b)
{
	Type temp = a;
	a = b;
	b = temp;

}

class Circle {
	friend float CirclePerm(int, float*);
private:
	// 计算当前所选择圆的圆心横坐标
	float Center(int t) {
		float temp = 0;
		for (int j = 1; j < t; j++) {
			float valuex = x[j] + 2.0 * sqrt(r[t] * r[j]);
			if (valuex > temp) {
				temp = valuex;
			}
		}
		return temp;
	}

	// 计算当前圆排列的长度
	void Compute(void) {
		float low = 0, high = 0;
		for (int i = 1; i <= n; i++) {
			if (x[i] - r[i] < low) {
				low = x[i] - r[i];
			}

			if (x[i] + r[i] > high) {
				high = x[i] + r[i];
			}
		}
		if (high - low < min) {
			min = high - low;
		}
	}

	//回溯
	void Backtrack(int t) {
		if (t > n) {
			Compute();
		}
		else {
			for (int j = t; j <= n; j++) {
				Swap(r[t], r[j]);
				float centerx = Center(t);
				//下界约束
				if (centerx + r[t] + r[1] < min) {
					x[t] = centerx;
					Backtrack(t + 1);
				}
				Swap(r[t], r[j]);
			}
		}
	}

	float min,	//当前最优值
		* x,   //圆心横坐标
		* r;   //圆排列
	int n;      //圆排列中圆的个数
};

float CirclePerm(int n, float* a)
{
	Circle X;
	X.n = n;
	X.r = a;
	X.min = 100000;
	float* x = new float[n + 1];
	X.x = x;
	X.Backtrack(1);
	delete[]x;
	return X.min;
}

int main()
{
	int n;
	float* a = new float[10];
	cout << "请输入圆的数量(<100)" << endl;
	cin >> n;

	cout << "请依次输入圆的半径" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << "圆排列中各圆的半径分别为：" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "最小圆排列长度为：";
	cout << CirclePerm(n, a) << endl;
	return 0;
}
