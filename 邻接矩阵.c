#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int visit[6] = { 0 };

//创建图
void create_graph(int arr[6][6])
{
	printf("\n请输入边的两个端点（输入0 0代表结束）：>");
	int a, b;
	scanf("%d%d", &a, &b);
	if (!a && !b)
		return;
	arr[a][b] = 1;
	arr[b][a] = 1;
	create_graph(arr);
}

//增加边
void add_edge(int arr[6][6])
{
	printf("\n接下来是插入边，你想在那两个端点插入边：");
	int a, b;
	scanf("%d%d", &a, &b);
	if (arr[a][b])
	{
		printf("已经有边了！请重新插入！\n");
		add_edge(arr);
		return;
	}
	arr[a][b] = 1;
	arr[b][a] = 1;
	printf("添加成功！！！\n");
	return;
}

//删除边
void dele_edge(int arr[6][6])
{
	printf("\n接下来是删除边，请问你想删除哪两个端点之间的边？\n请输入：>");
	int a, b;
	scanf("%d%d", &a, &b);
	if (!arr[a][b])
	{
		printf("这两个端点之间，没有边，请换端点！！！\n");
		dele_edge(arr);
		return;
	}
	arr[a][b] = 0;
	arr[b][a] = 0;
	printf("删除成功！！！\n");
	return;
}

//删除结点
void dele_node(int arr[6][6])
{
	printf("\n接下来是删除结点，请问你想删除第几个结点？\n");
	printf("请输入：>");
	int a;
	scanf("%d", &a);
	if (a < 0 || a>5)
	{
		printf("没有这个结点，请重新输入！！!\n");
		dele_node(arr);
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		arr[a][i] = 0;
		arr[i][a] = 0;
	}
	printf("删除结点成功！！！\n");
	return;
}

//打印矩阵
void print_graph(int arr[6][6])
{
	printf("  0 1 2 3 4 5\n");
	int i, j;
	for (i = 0; i < 6; i++)
	{
		printf("%d ", i);
		for (j = 0; j < 6; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//深度优先遍历
void depth_print(int arr[6][6], int k)
{
	visit[k] = 1;
	printf("%d ", k);
	int i;
	for (i = 0; i < 6; i++)
	{
		if (arr[k][i] == 1 && visit[i] == 0)
		{
			depth_print(arr, i);
		}
	}
}
void DFS(int arr[6][6])
{
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		visit[i] = 0;
	}
	for (i = 0; i < 6; i++)
	{
		if (visit[i] == 0)
		{
			depth_print(arr, i);
		}
	}
}

//广度优先遍历
void width_print(int arr[6][6])
{
	int num[6];
	int base = 0, top = 0, i, j, k;
	for (i = 0; i < 6; i++)
	{
		visit[i] = 0;
	}
	for (i = 0; i < 6; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			num[top++] = i;
		}
		while (base < top)
		{
			k = num[base++];
			printf("%d ", k);
			for (j = 0; j < 6; j++)
			{
				if (arr[k][j] == 1 && visit[j] == 0)
				{
					visit[j] = 1;
					num[top++] = j;
				}
			}
		}
	}
}

int main()
{
	int i;
	int arr[6][6] = { 0 };
	create_graph(arr);
	printf("\n图的矩阵为\n");
	print_graph(arr);
	printf("\n深度优先遍历：\n");
	DFS(arr);
	printf("\n广度优先遍历：\n");
	width_print(arr);
	add_edge(arr);//添加边
	printf("\n图的矩阵为\n");
	print_graph(arr);
	dele_edge(arr);//删除边
	printf("\n图的矩阵为\n");
	print_graph(arr);
	dele_node(arr);//删除结点
	printf("\n图的矩阵为\n");
	print_graph(arr);
	printf("程序结束！！！\n");
	return 0;
}
//
//0 2
//0 4
//0 5
//1 2
//1 4
//2 3
//2 5
//0 0

