#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node, * Linklist;

//初始化链表
void init_list(Linklist* s)
{
	*s = (Linklist)malloc(sizeof(Node));
	if (!(*s))
	{
		printf("出现错误！！！\n");
		exit(1);
	}
}

//创建链表
void creat_list(Linklist* head, int n)
{
	init_list(head);
	Linklist p1 = *head, p2 = NULL;
	p1->data = n;//存放数据个数
	p1->next = NULL;
	if (0 == n)//0个元素，出错
	{
		printf("出现错误！！！\n");
		exit(1);
	}
	else
	{
		printf("请输入数据：>\n");
		int input, i = 1;
		while (i <= n)
		{
			init_list(&p2);
			scanf("%d", &input);
			p2->data = input;
			p2->next = NULL;
			p1->next = p2;
			p1 = p2;
			i++;
		}
	}
}

//遍历链表
void read_list(Linklist head)
{
	Linklist p = head;
	printf("链表长度为%d，元素分别为\n", p->data);
	p = p->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//插入元素
void insert_list(Linklist* head, int insertPosition)
{
	Linklist p1 = *head, p2 = p1->next, insert_p = NULL;
	int i = 1, input;
	if (insertPosition > p1->data || insertPosition < 1)//插入位置不在1到head->data之间，出错
	{
		printf("出现错误！！！\n");
		exit(1);
	}
	p1->data += 1;
	while (i < insertPosition)
	{
		p1 = p2;
		p2 = p2->next;
		i++;
	}
	init_list(&insert_p);
	printf("你要插入的元素是：>");
	scanf("%d", &input);
	insert_p->data = input;
	insert_p->next = p2;
	p1->next = insert_p;
}

//删除元素
void del_list(Linklist* head, int deletePosition)
{
	int i = 1;
	Linklist p1 = *head, p2 = p1->next, q;
	if (deletePosition<1 || deletePosition>p1->data)//删除位置不在1到head->data之间，出错
	{
		printf("出现错误！！！\n");
		exit(1);
	}
	p1->data -= 1;
	while (i < deletePosition)
	{
		p1 = p2;
		p2 = p2->next;
		i++;
	}
	q = p2;
	p1->next = q->next;
	free(p2);
}

//查找元素,赋值给getnum
void get_list(Linklist head, int* getnum, int getnumPos)
{
	if (getnumPos<1 || getnumPos>head->data)//取的数位置不在1到head->data之间，出错
	{
		printf("出现错误！！！\n");
		exit(1);
	}
	int i = 1;
	Linklist p1 = head->next;
	while (i < getnumPos)
	{
		p1 = p1->next;
		i++;
	}
	*getnum = p1->data;
}

//摧毁链表
void destroy(Linklist* head)
{
	Linklist p1 = *head, p2 = NULL;
	while (p1)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	free(p2);
}

int main()
{
	int n, insertPosition, deletePosition, getnum, getnumPos;
	Linklist head;
	printf("先是创建链表\n");
	printf("请输入元素个数：>");
	scanf("%d", &n);
	creat_list(&head, n);
	read_list(head);
	printf("接下来是插入元素，请问您想在第几个元素前插入一个元素呢？\n请输入：>");
	scanf("%d", &insertPosition);
	insert_list(&head, insertPosition);
	printf("插入后：\n");
	read_list(head);
	printf("接下来是删除元素，请问您想删除第几个元素呢？\n请输入：>");
	scanf("%d", &deletePosition);
	del_list(&head, deletePosition);
	printf("删除后：\n");
	read_list(head);
	printf("接下来是查找元素，请问您想查找第几个元素呢？\n请输入：>");
	scanf("%d", &getnumPos);
	get_list(head, &getnum, getnumPos);
	printf("第%d个元素是%d\n", getnumPos, getnum);
	printf("链表基本操作都完成了，是时候摧毁链表了！\n");
	destroy(&head);
	printf("摧毁完成，程序结束\n");
}