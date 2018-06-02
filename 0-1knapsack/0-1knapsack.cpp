// 0-1knapsack.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


/*定义结构体物品*/
struct a
{
	int v, w;//v为价值w为物品重量  
} a[11];
int main()
{
	int i, j, sum, s, m, n;
	struct a t;
	scanf_s("%d", &n);
	while (n--)
	{
		sum = 0;
		printf("input the number of items and the knapsack capacity:\n");
		scanf_s("%d%d", &s, &m);//s为物品个数，m，为背包容量  
		printf("input value and weight:\n");
		for (i = 0; i<s; i++)
			scanf_s("%d%d", &a[i].v, &a[i].w);

		/*特别注意冒泡排序输出从大到小*/

		for (i = 0; i<s; i++)
		{
			for (j = i + 1; j<s; j++)
			{
				if (a[j].v>a[i].v)
				{
					t = a[j];
					a[j] = a[i];
					a[i] = t;
				}
			}
		}
		/*贪心算法核心*/
		for (i = 0; i<s; i++)
		{
			if (m<a[i].w)
			{
				sum = sum + a[i].v*m;//背包可拆  
				m = 0;
				break;
			}
			else
			{
				sum = sum + a[i].v*a[i].w;
				m = m - a[i].w;
			}
		}
		printf("result:%d\n", sum);
	}
	return 0;
}