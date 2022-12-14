#define _CRT_SECURE_NO_WARNINGS

//构造哈夫曼树，求解哈夫曼编码

typedef struct tree
{
	int weight;
	int data;
	int parent;
	int LeftChild;
	int RightChild;
}HFtree,*LinkTree;

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//创建哈夫曼树
void create_tree(LinkTree* tree, int num)
{
	(*tree) = (LinkTree)malloc(sizeof(HFtree) * (2 * num - 1));
	int i, j, min1, min2, min;
	for (i = 0; i < num; i++)
	{
		printf("新建一个结点，请先后输入权重和数据:>");
		scanf("%d", &((*tree) + i)->weight);
		scanf("%d", &((*tree) + i)->data);
		((*tree) + i)->parent = -1;
		((*tree) + i)->LeftChild = -1;
		((*tree) + i)->RightChild = -1;
	}
	for (i = num; i < 2 * num - 1; i++)
	{
		min1 = -1;
		min2 = -1;
		min = 0;
		for (j = 0; j < i; j++)
		{
			if (((*tree) + j)->parent == -1)
				if (min1 == -1)
					min1 = j;
				else
					if (min2 == -1)
						min2 = j;
					else
						if (((*tree) + min1)->weight > ((*tree) + min2)->weight)
						{
							if (((*tree) + min1)->weight > ((*tree) + j)->weight)
								min1 = j;
						}
						else
						{
							if (((*tree) + min2)->weight > ((*tree) + j)->weight)
								min2 = j;
						}
		}//选出权重最小的两个
		((*tree) + i)->weight = ((*tree) + min1)->weight + ((*tree) + min2)->weight;
		((*tree) + i)->data = -1;
		((*tree) + i)->parent = -1;
		((*tree) + i)->LeftChild = min1 > min2 ? min2 : min1;
		((*tree) + i)->RightChild = min1 < min2 ? min2 : min1;
		((*tree) + min1)->parent = i;
		((*tree) + min2)->parent = i;
	}
}

//打印每个元素对应的编码
void print_tree(LinkTree tree)
{
	char stack[8];
	int root, i, j, k;//i是循环计数，j是等于i来操作，k是栈顶指针
	root = 0;
	while (tree[root].parent != -1)//找到根，确定元素个数
		root++;
	for (i = 0; i <= root / 2; i++)
	{
		j = i; k = 0;
		while (tree[j].parent != -1)
		{
			if (tree[tree[j].parent].LeftChild == j)
				stack[k++] = '0';
			else
				stack[k++] = '1';
			j = tree[j].parent;
		}
		printf("%d：", tree[i].data);
		while (k)
			printf("%c", stack[--k]);
		printf("\n");
	}
}

int main()
{
	int n;
	printf("你想创建几个结点？请输入：>\n");
	scanf("%d", &n);
	LinkTree tree = NULL;
	create_tree(&tree, n);
	printf("\n");
	printf("这些数所对应的哈夫曼编码分别为:\n");
	print_tree(tree);
	return 0;
}

//
//8
//8 0
//7 1
//2 2
//5 3
//1 4
//3 5
//6 6
//4 7
