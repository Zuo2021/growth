#define _CRT_SECURE_NO_WARNINGS

#define MAX 6
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int visit[MAX] = { 0 };

typedef struct node
{
	int data;//数据
	struct node* next;
}Node,*LinkNode;

typedef struct list
{
	int number;//编号
	LinkNode p;//链表
}List;

void initial(LinkNode* p)
{
	(*p)->data = -1;
	(*p)->next = NULL;
}

void create_graph(List graph[MAX])
{
	printf("请输入结点的内容：>");
	int input, i, a, b;
	for (i = 0; i < MAX; i++)
	{
		scanf("%d", &graph[i].number);
		graph[i].p = (LinkNode)malloc(sizeof(Node));
		initial(&graph[i].p);
	}
	printf("请输入边的两端：>\n");
	scanf("%d%d", &a, &b);
	while (a != 0 || b != 0)
	{
		LinkNode q1 = graph[a].p, q2 = graph[b].p;
		LinkNode p1 = (LinkNode)malloc(sizeof(Node));
		LinkNode p2 = (LinkNode)malloc(sizeof(Node));
		p1->data = b; p2->data = a;
		p1->next = q1->next; p2->next = q2->next;
		q1->next = p1; q2->next = p2;
		printf("请输入边的两端：>\n");
		scanf("%d%d", &a, &b);
	}
}

//深度优先遍历
void depth_print(List graph[MAX], int k)
{
	LinkNode q = graph[k].p->next;
	while (q)
	{
		if (visit[q->data] == 0)
		{
			visit[q->data] = 1;
			printf("%d ", q->data);
			depth_print(graph, q->data);
		}
		q = q->next;
	}
}
void DFS(List graph[MAX])
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		visit[i] = 0;
	}
	for (i = 0; i < MAX; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			printf("%d ", graph[i].number);
			depth_print(graph, i);
		}
	}
}

//广度优先遍历
void BFS(List graph[MAX])
{
	int num[MAX];
	int i, base = 0, top = 0;
	for (i = 0; i < MAX; i++)
	{
		visit[i] = 0;
	}
	for (i = 0; i < MAX; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			num[top++] = graph[i].number;
		}
		while (base < top)
		{
			int k = num[base++];
			printf("%d ", graph[k].number);
			LinkNode q = graph[k].p->next;
			while (q)
			{
				if (visit[q->data] == 0)
				{
					visit[q->data] = 1;
					num[top++] = q->data;
				}
				q = q->next;
			}
		}
	}
}

//加边
void add_edge(List graph[MAX])
{
	printf("\n你想添加哪两个端点的边？请输入：>\n");
	int a, b;
	scanf("%d%d", &a, &b);
	LinkNode q1 = graph[a].p, q2 = graph[b].p;
	LinkNode p1 = (LinkNode)malloc(sizeof(Node));
	LinkNode p2 = (LinkNode)malloc(sizeof(Node));
	p1->data = b; p2->data = a;
	p1->next = q1->next; p2->next = q2->next;
	q1->next = p1; q2->next = p2;
}

//减边
void dele_edge(List graph[MAX])
{
	printf("\n你现在要删一条边，你要删哪一条\n请输入两个端点：>");
	int a, b;
	scanf("%d%d", &a, &b);
	LinkNode q1_1 = graph[a].p->next, q2_1 = graph[b].p->next;
	LinkNode q1_2 = graph[a].p, q2_2 = graph[b].p;

	while (q1_1->data != b)
	{
		q1_2 = q1_2->next;
		q1_1 = q1_1->next;
	}
	q1_2->next = q1_1->next;
	free(q1_1);

	while (q2_1->data != a)
	{
		q2_2 = q2_2->next;
		q2_1 = q2_1->next;
	}
	q2_2->next = q2_1->next;
	free(q2_1);
}

//打印表
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

//删除结点
void dele_node(List graph[MAX])
{
	printf("\n\n现在你要删除一个结点，请问你想删除那个结点，请输入：>");
	int k = 0;
	scanf("%d", &k);
	int i = 0; LinkNode p, q;
	for (i = 0; i < MAX; i++)
	{
		if (graph[i].number == k)
		{
			graph[i].number = -1;
			p = graph[i].p;
			q = p->next;
			while (p)
			{
				free(p);
				p = q;
				if (q)
					q = q->next;
			}
		}
		else
		{
			p = graph[i].p;
			q = p->next;
			while (q)
			{
				if (q->data == k)
				{
					p->next = q->next;
					free(q);
					break;
				}
				else
				{
					p = q;
					q = q->next;
				}
			}
		}
	}
}

int main()
{
	List graph[MAX];
	create_graph(graph);
	print(graph);
	printf("\n深度优先遍历：\n");
	DFS(graph);
	printf("\n广度优先遍历：\n");
	BFS(graph);
	add_edge(graph);
	print(graph);
	dele_edge(graph);
	print(graph);
	dele_node(graph);
	print(graph);
	return 0;
}


//0 2
//0 4
//0 5
//1 2
//1 4
//2 3
//2 5
//0 0
