#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAX 6

int visit[MAX] = { 0 };

typedef struct node
{
	int data;//����
	struct node* next;
}Node, * LinkNode;

typedef struct list
{
	int number;//���
	LinkNode p;//����
}List;

void initial(LinkNode* p)
{
	(*p)->data = -1;
	(*p)->next = NULL;
}

void create_graph(List graph[MAX])
{
	printf("������������ݣ�>");
	int input, i, a, b;
	for (i = 0; i < MAX; i++)
	{
		scanf("%d", &graph[i].number);
		graph[i].p = (LinkNode)malloc(sizeof(Node));
		initial(&graph[i].p);
	}
	printf("������ߵ����ˣ�>\n");
	scanf("%d%d", &a, &b);
	while (a != 0 || b != 0)
	{
		LinkNode q1 = graph[a].p, q2 = graph[b].p;
		LinkNode p1 = (LinkNode)malloc(sizeof(Node));
		LinkNode p2 = (LinkNode)malloc(sizeof(Node));
		p1->data = b; p2->data = a;
		p1->next = q1->next; p2->next = q2->next;
		q1->next = p1; q2->next = p2;
		printf("������ߵ����ˣ�>\n");
		scanf("%d%d", &a, &b);
	}
}

void print(List graph[MAX])
{
	printf("\n");
	int i = 0;
	LinkNode p;
	for (i = 0; i < MAX; i++)
	{
		if (graph[i].number != -1)
		{
			printf("%d", graph[i].number);
			p = graph[i].p->next;
			while (p)
			{
				printf(" -> ");
				printf("%d", p->data);
				p = p->next;
			}
			printf("\n");
		}
	}
}

int examination(List graph[MAX], int start, int end, int lenth)
{
	if (lenth == 0 && start == end)
		return 1;
	LinkNode p = graph[start].p->next;
	int ret = 0;
	int i = 0;
	visit[start] = 1;
	while (p)
	{
		if (!visit[p->data])
		{
			visit[p->data] = 1;
			if (examination(graph, p->data, end, lenth - 1))
				return 1;
			visit[p->data] = 0;
		}
		p = p->next;
	}
	return 0;;
}

int main()
{
	int a = 0, b = 0, lenth = 0;
	List graph[MAX];
	create_graph(graph);
	print(graph);
	for (a = 0; a < MAX; a++)
		visit[a] = 0;
	while (1)
	{
		printf("�������������֮���Ƿ��м�·��(����0 0 0����)\n����������������Ԥ�Ƴ���:>");
		scanf("%d%d%d", &a, &b, &lenth);
		if (!a && !b && !lenth)
		{
			break;
		}
		if (examination(graph, a, b, lenth))
			printf("�м�·��������\n");
		else
			printf("�޼�·��������\n");
	}
	return 0;
}


//0 1 2 3 4 5
//0 1
//0 4
//0 5
//1 2
//1 3
//3 5
//0 0
