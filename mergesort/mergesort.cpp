// mergesort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#define MAX 100
int a[MAX], temp[MAX];//原数组a，临时空间数组temp


void merge(int low, int mid, int high) {
	int i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high)
		if (a[i]<a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= high)
		temp[k++] = a[j++];
	for (i = low; i <= high; i++) {
		a[i] = temp[i];
	}
}

void mergesort(int a, int b) {
	if (a<b) {
		int mid = (a + b) / 2;
		mergesort(a, mid);
		mergesort(mid + 1, b);
		merge(a, mid, b);
	}
}

void main() {
	int i, n;
	printf("请输入元素个数：");
	scanf_s("%d", &n);
	printf("请依次输入每个元素：\n");
	for (i = 0; i < n; ++i) {
		a[i] = rand() % n;
		printf("%5d", a[i]);
	}
	mergesort(1, n);
	printf("\n");
	printf("排序后的序列为：\n");
	for (i = 0; i < n; ++i) {
		printf("%5d", a[i]);
	}
	printf("\n");
}