# define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct btnode
{
	int data;
	struct BiTNode *Lchild, *Rchild;
}BTNode,*BiTree;

//��ʼ�����
void init_Tree(BiTree *root)
{
	*root = (BiTree)malloc(sizeof(BTNode));
	if (!root)
		exit(1);
	(*root)->data = -1;
	(*root)->Lchild = NULL;
	(*root)->Rchild = NULL;
}

//����������
void creat_Tree(BiTree* s)
{
	int n;
	scanf("%d", &n);
	if (n == -1)
		return;
	else
	{
		init_Tree(s);
		(*s)->data = n;
		creat_Tree(&((*s)->Lchild));
		creat_Tree(&((*s)->Rchild));
	}
}

//�������������
void DLR_Tree(BiTree root)
{
	if (!root)
	{
		return;
	}
	printf("%d ", root->data);
	DLR_Tree(root->Lchild);
	DLR_Tree(root->Rchild);
}

//�������������
void LDR_Tree(BiTree root)
{
	if (!root)
	{
		return;
	}
	LDR_Tree(root->Lchild);
	printf("%d ", root->data);
	LDR_Tree(root->Rchild);
}

//�������������
void LRD_Tree(BiTree root)
{
	if (!root)
	{
		return;
	}
	LRD_Tree(root->Lchild);
	LRD_Tree(root->Rchild);
	printf("%d ", root->data);
}

//��Ҷ����
int leaf_num(BiTree root)
{
	if (!root->Lchild && !root->Rchild)
		return 1;
	else if (!root->Lchild && root->Rchild)
		return leaf_num(root->Rchild);
	else if (root->Lchild && !root->Rchild)
		return leaf_num(root->Lchild);
	else
		return leaf_num(root->Lchild) + leaf_num(root->Rchild);
}

//������
int node_num(BiTree root)
{
	if (!root)
		return 0;
	else
		return node_num(root->Lchild) + node_num(root->Rchild) + 1;
}

//���������
int depth(BiTree root)
{
	if (!root)
		return 0;
	return 1 + (depth(root->Lchild) > depth(root->Rchild) ? depth(root->Lchild) : depth(root->Rchild));
}

//�ݻ���
void destroy(BiTree root)
{
	if (!root)
		return;
	destroy(root->Lchild);
	destroy(root->Rchild);
	free(root);
}

int main()
{
	BiTree root;
	creat_Tree(&root);
	printf("���������");
	DLR_Tree(root);
	printf("\n���������");
	LDR_Tree(root);
	printf("\n���������");
	LRD_Tree(root);
	printf("\n");
	printf("Ҷ������%d\n", leaf_num(root));
	printf("�ڵ�����%d\n", node_num(root));
	printf("������ȣ�%d\n", depth(root));
	destroy(root);
	printf("�������ݻ���ɣ�����\n�������������");
	return 0;
}

//1 2 4 -1 -1 5 7 -1 -1 -1 3 6 -1 -1 -1