#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int visit[6] = { 0 };

//����ͼ
void create_graph(int arr[6][6])
{
	printf("\n������ߵ������˵㣨����0 0�����������>");
	int a, b;
	scanf("%d%d", &a, &b);
	if (!a && !b)
		return;
	arr[a][b] = 1;
	arr[b][a] = 1;
	create_graph(arr);
}

//���ӱ�
void add_edge(int arr[6][6])
{
	printf("\n�������ǲ���ߣ��������������˵����ߣ�");
	int a, b;
	scanf("%d%d", &a, &b);
	if (arr[a][b])
	{
		printf("�Ѿ��б��ˣ������²��룡\n");
		add_edge(arr);
		return;
	}
	arr[a][b] = 1;
	arr[b][a] = 1;
	printf("��ӳɹ�������\n");
	return;
}

//ɾ����
void dele_edge(int arr[6][6])
{
	printf("\n��������ɾ���ߣ���������ɾ���������˵�֮��ıߣ�\n�����룺>");
	int a, b;
	scanf("%d%d", &a, &b);
	if (!arr[a][b])
	{
		printf("�������˵�֮�䣬û�бߣ��뻻�˵㣡����\n");
		dele_edge(arr);
		return;
	}
	arr[a][b] = 0;
	arr[b][a] = 0;
	printf("ɾ���ɹ�������\n");
	return;
}

//ɾ�����
void dele_node(int arr[6][6])
{
	printf("\n��������ɾ����㣬��������ɾ���ڼ�����㣿\n");
	printf("�����룺>");
	int a;
	scanf("%d", &a);
	if (a < 0 || a>5)
	{
		printf("û�������㣬���������룡��!\n");
		dele_node(arr);
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		arr[a][i] = 0;
		arr[i][a] = 0;
	}
	printf("ɾ�����ɹ�������\n");
	return;
}

//��ӡ����
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

//������ȱ���
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

//������ȱ���
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
	printf("\nͼ�ľ���Ϊ\n");
	print_graph(arr);
	printf("\n������ȱ�����\n");
	DFS(arr);
	printf("\n������ȱ�����\n");
	width_print(arr);
	add_edge(arr);//��ӱ�
	printf("\nͼ�ľ���Ϊ\n");
	print_graph(arr);
	dele_edge(arr);//ɾ����
	printf("\nͼ�ľ���Ϊ\n");
	print_graph(arr);
	dele_node(arr);//ɾ�����
	printf("\nͼ�ľ���Ϊ\n");
	print_graph(arr);
	printf("�������������\n");
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

