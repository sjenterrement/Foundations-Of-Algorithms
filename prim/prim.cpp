// prim.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define MAX  1000


typedef struct
{
	int n;
	char vexs[6];
	int arcs[6][6];
}GraphMatrix;

typedef struct
{
	int start_vex, stop_vex;
	int weight;
}Edge;

void Prim(GraphMatrix* pgraph, Edge *mst)
{
	int i, j, min, vx, vy;

	int weight, minweight;

	Edge edge;
	for (i = 0; i<pgraph->n - 1; i++)
	{
		mst[i].start_vex = 0;
		mst[i].stop_vex = i + 1;
		mst[i].weight = pgraph->arcs[0][i + 1];
	}
	for (i = 0; i<pgraph->n - 1; i++)
	{
		minweight = MAX;
		min = -1;
		for (j = i; j<pgraph->n - 1; j++)
		{
			if (mst[j].weight<minweight)
			{
				minweight = mst[j].weight;
				min = j;
			}
			edge = mst[min];
			mst[min] = mst[i];
			mst[i] = edge;
			vx = mst[i].stop_vex;
			for (j = i + 1; j < pgraph->n - 1; j++)
			{
				vy = mst[j].stop_vex;
				weight = pgraph->arcs[vx][vy];
				if (weight<mst[j].weight)
				{
					mst[j].weight = weight;
					mst[j].start_vex = vx;
				}
			}
		}
	}
}
void print(GraphMatrix* pgraph, Edge *mst)
{
	int i;
	for (i = 0; i<pgraph->n - 1; i++)
		printf("%d---%d   %d\n", mst[i].start_vex, mst[i].stop_vex, mst[i].weight);
}

void main()
{
	Edge mst[5];
	GraphMatrix g;
	g.n = 6;
	g.vexs[0] = 'a';
	g.vexs[1] = 'b';
	g.vexs[2] = 'c';
	g.vexs[3] = 'd';
	g.vexs[4] = 'e';
	g.vexs[5] = 'f';


	int a[6][6] =
	{
	{ 0,10,MAX,MAX,19,21 },
	{ 10,0,5,6,MAX,11 },
	{ MAX,5,0,6,MAX,MAX },
	{ MAX,6,6,0,18,14 },
	{ 19,MAX,MAX,18,0,33 },
	{ 21,11,MAX,14,33,0 }
	};


	for (int i = 0; i<6; i++)
		for (int j = 0; j<6; j++)
			g.arcs[i][j] = a[i][j];
	Prim(&g, mst);
	print(&g, mst);
}

