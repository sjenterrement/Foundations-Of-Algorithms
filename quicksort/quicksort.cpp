// quicksort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<time.h>
#include<stdlib.h>
#define MAX 100


void quicksort(int S[], int l, int h) {
	if (l<h) {
		int i = l, j = h, x = S[l];
		while (i<j) {
			while (i<j&&S[j] >= x)//从右往左找找第一个小于x的数
				j--;
			if (i<j)
				S[i++] = S[j];
			while(i<j&&S[i] <= x)//从左往右找第一个大于x的数
				i++;
			if (i<j)
				S[j--] = S[i];
		}
		S[i] = x;//i=j时，将x填入中间位置
		quicksort(S, l, i - 1);//递归调用
		quicksort(S, i + 1, h);
	}
}

int main() {
	//计时
	clock_t start, finish;
	double totaltime;
	

	//运行主程序
	int n, a[MAX];
	printf("请输入元素个数：");
	scanf_s("%d", &n);
	printf("请依次输入元素：\n");
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
		printf("%5d", a[i]);
	}

	printf("\n");

	start = clock();

	quicksort(a, 0, n);

	finish = clock();

	printf("排序后的序列为:\n");
	for (int i = 1; i < n+1; i++)
	{
		printf("%5d", a[i]);
	}
	
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;

	printf("\n程序运行的时间： %.5f秒\n", totaltime);
}
