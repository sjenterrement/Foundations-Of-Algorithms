// fibonacci.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<time.h>

int fib(int n);
double fib2(int n);
clock_t a1, b1, a2, b2;

int main() {
	int n;
	double a1, a2, b1, b2, t1, t2;
	printf("请输入斐波那契数列的项数: ");
	scanf_s("%d", &n);
	a2 = clock();
	printf("\n动态规划求解第%d项斐波那契数列的数值： %.0f \n\n", n, fib2(n));
	b2 = clock();
	t2 = (b2 - a2) / CLOCKS_PER_SEC;
	printf("动态规划所需时间=%.6f秒\n\n", t2);
	a1 = clock();
	printf("分治法求解第%d项斐波那契数列的数值为: %d \n\n", n, fib(n));
	b1 = clock();
	t1 = (b1 - a1) / CLOCKS_PER_SEC;
	printf("分治求法所需时间=%.6f秒\n\n", t1);
	printf("动态规划比分治法快%.2f倍\n\n", t1 / t2);
	return 0;
}

int fib(int n) {
	if (n<0)
		return 0;
	else if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
//动态规划算法
double fib2(int n) {
	int i = 0;
	double first = 1, second = 1;
	double result = 0;
	if (n<0)
		return 0;
	else
	{

		for (i = 3; i <= n; i++) {
			result = first + second;
			first = second;
			second = result;
		}
		return result;
	}
}
