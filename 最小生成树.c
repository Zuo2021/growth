#define _CRT_SECURE_NO_WARNINGS

#define MAX 6
#define N 2147483647
#include<stdio.h>

void create_graph(int graph[MAX][MAX])
{
	int a, b, weight;
	printf("请输入边的两个端点和对应的权值：>");
	scanf("%d%d%d", &a, &b, &weight);
	if (!a && !b && !weight)//三个都是0结束创建
		return;
	graph[a][b] = weight;
	graph[b][a] = weight;
	create_graph(graph);
}

void prim(int graph[MAX][MAX], int k)
{
	int visit[MAX] = { 0 };
	int lowcost[MAX];
	int from[MAX];
	int i, j, minid;

	for (i = 0; i < MAX; i++)//初始化
	{
		from[i] = -1;
		lowcost[i] = N;
	}

	i = 0;
	while (i < MAX)//以k初始化
	{
		if (graph[k][i])
		{
			lowcost[i] = graph[k][i];
			from[i] = k;
		}
		i++;
	}
	visit[k] = 1;

	for (i = 1; i < MAX; i++)
	{

		minid = k;
		for (j = 0; j < MAX; j++)
		{
			if (!visit[j] && lowcost[j] < lowcost[minid])
			{
				minid = j;
			}
		}

		printf("%d -> %d  cost:%d\n", from[minid], minid, lowcost[minid]);

		visit[minid] = 1;
		from[minid] = -1;
		lowcost[minid] = N;

		for (j = 0; j < MAX; j++)
		{
 			if (!visit[j] && graph[minid][j])
			{
				if (lowcost[j] > graph[minid][j])
				{
					lowcost[j] = graph[minid][j];
					from[j] = minid;
				}
			}
		}
	}
 }

int main()
{
	int graph[MAX][MAX];
	int i, j, k;
	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
			graph[i][j] = 0;
	printf("先创建一个图(输入三个0结束创建)\n\n");
	create_graph(graph);
	printf("接下来是创建最小生成树，请输入开始顶点:>");
	scanf("%d", &k);
	prim(graph, k);
	return 0;
}

//0 1 1
//0 2 2
//1 3 4
//1 5 3
//2 3 6
//3 5 8
//3 4 7
//4 5 9
//0 0 0
