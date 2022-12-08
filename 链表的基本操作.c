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

//��ʼ������
void init_list(Linklist* s)
{
	*s = (Linklist)malloc(sizeof(Node));
	if (!(*s))
	{
		printf("���ִ��󣡣���\n");
		exit(1);
	}
}

//��������
void creat_list(Linklist* head, int n)
{
	init_list(head);
	Linklist p1 = *head, p2 = NULL;
	p1->data = n;//������ݸ���
	p1->next = NULL;
	if (0 == n)//0��Ԫ�أ�����
	{
		printf("���ִ��󣡣���\n");
		exit(1);
	}
	else
	{
		printf("���������ݣ�>\n");
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

//��������
void read_list(Linklist head)
{
	Linklist p = head;
	printf("������Ϊ%d��Ԫ�طֱ�Ϊ\n", p->data);
	p = p->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//����Ԫ��
void insert_list(Linklist* head, int insertPosition)
{
	Linklist p1 = *head, p2 = p1->next, insert_p = NULL;
	int i = 1, input;
	if (insertPosition > p1->data || insertPosition < 1)//����λ�ò���1��head->data֮�䣬����
	{
		printf("���ִ��󣡣���\n");
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
	printf("��Ҫ�����Ԫ���ǣ�>");
	scanf("%d", &input);
	insert_p->data = input;
	insert_p->next = p2;
	p1->next = insert_p;
}

//ɾ��Ԫ��
void del_list(Linklist* head, int deletePosition)
{
	int i = 1;
	Linklist p1 = *head, p2 = p1->next, q;
	if (deletePosition<1 || deletePosition>p1->data)//ɾ��λ�ò���1��head->data֮�䣬����
	{
		printf("���ִ��󣡣���\n");
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

//����Ԫ��,��ֵ��getnum
void get_list(Linklist head, int* getnum, int getnumPos)
{
	if (getnumPos<1 || getnumPos>head->data)//ȡ����λ�ò���1��head->data֮�䣬����
	{
		printf("���ִ��󣡣���\n");
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

//�ݻ�����
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
	printf("���Ǵ�������\n");
	printf("������Ԫ�ظ�����>");
	scanf("%d", &n);
	creat_list(&head, n);
	read_list(head);
	printf("�������ǲ���Ԫ�أ����������ڵڼ���Ԫ��ǰ����һ��Ԫ���أ�\n�����룺>");
	scanf("%d", &insertPosition);
	insert_list(&head, insertPosition);
	printf("�����\n");
	read_list(head);
	printf("��������ɾ��Ԫ�أ���������ɾ���ڼ���Ԫ���أ�\n�����룺>");
	scanf("%d", &deletePosition);
	del_list(&head, deletePosition);
	printf("ɾ����\n");
	read_list(head);
	printf("�������ǲ���Ԫ�أ�����������ҵڼ���Ԫ���أ�\n�����룺>");
	scanf("%d", &getnumPos);
	get_list(head, &getnum, getnumPos);
	printf("��%d��Ԫ����%d\n", getnumPos, getnum);
	printf("�����������������ˣ���ʱ��ݻ������ˣ�\n");
	destroy(&head);
	printf("�ݻ���ɣ��������\n");
}