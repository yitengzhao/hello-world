#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<malloc.h>
#include<stack>
#include<queue>
#define MAX 20
using namespace std;
typedef struct BTNode {       /*节点结构声明*/
	char data;               /*节点数据*/
	struct BTNode *lchild;
	struct BTNode *rchild;  /*指针*/
}*BiTree;

void createBiTree(BiTree *t) { /* 先序遍历创建二叉树*/
	char s;
	BiTree q;
	printf("\nplease input data:(exit for #)");
	cin>>s;
	if (s == '#') { *t = NULL; return; }
	q = (BiTree)malloc(sizeof(struct BTNode));
	if (q == NULL) { printf("Memory alloc failure!"); exit(0); }
	q->data = s;
	*t = q;
	createBiTree(&q->lchild); /*递归建立左子树*/
	createBiTree(&q->rchild); /*递归建立右子树*/
}

void PreOrder(BiTree p) {  /* 先序遍历二叉树*/
	if (p != NULL) {
		printf("%c", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}
void InOrder(BiTree p) {  /* 中序遍历二叉树*/
	if (p != NULL) {
		InOrder(p->lchild);
		printf("%c", p->data);
		InOrder(p->rchild);
	}
}
void PostOrder(BiTree p) {  /* 后序遍历二叉树*/
	if (p != NULL) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%c", p->data);
	}
}

/*先序遍历的非递归算法*/
void Preorder_n(BiTree p) { 
	BiTree stack[MAX], q;
	int top = 0, i;
	for (i = 0; i < MAX; i++) stack[i] = NULL;/*初始化栈*/
	q = p;
	while (q != NULL) {
		printf("%c", q->data);
		if (q->rchild != NULL) stack[top++] = q->rchild;
		if (q->lchild != NULL) q = q->lchild;
		else
			if (top > 0) q = stack[--top];
			else q = NULL;
	}
}

void release(BiTree t) { /*释放二叉树空间*/
	if (t != NULL) {
		release(t->lchild);
		release(t->rchild);
		free(t);
	}
}

//统计二叉树的深度
int Depth(BiTree T)
{
	if (T == NULL)
		return 0;
	else
	{
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}

//统计二叉树节点总数
int NodeCount(BiTree T)
{
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
//二叉树的层次遍历
void QueueTraverse(BiTree T, queue<BiTree> &q)
{
	if (T == NULL)
		cout << "\n二叉树为空" << endl;
	else
		cout << "\n二叉树的层次遍历：";
	q.push(T);
	while (!q.empty())
	{
		queue<BiTree> temq;
		while (!q.empty())
		{
			BiTree temT = q.front();
			cout << q.front()->data ;
			q.pop();
			if (temT->lchild != NULL)
				temq.push(temT->lchild);
			if (temT->rchild != NULL)
				temq.push(temT->rchild);
		}
		q = temq;
	}
}

//二叉树中序非递归
void InOrderTraverse(BiTree T)
{
	stack<BiTree>s;
	BiTree tem = T;
	while (tem || !s.empty())
	{
		if (tem != NULL)
		{
			s.push(tem);
			tem = tem->lchild;
		}
		else
		{
			tem = s.top();
			s.pop();
			cout << tem->data;
			tem = tem->rchild;
		}
	}
}

//二叉树后序非递归
void PostOrderTraverse(BiTree T)
{
	stack<BiTree>s;
	BiTree tem = T;
	BiTree tmp;
	vector<char> v;
	while (tem != NULL||!s.empty())
	{
		while (tem != NULL)
		{
			v.push_back(tem->data);
			s.push(tem);
			tem = tem->rchild;
		}
		if (!s.empty())
		{
			tmp = s.top();
			s.pop();
			tem = tmp->lchild;
		}
	}
	reverse(v.begin(), v.end());
	vector<char>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it;
	cout << endl;
}

//统计二叉树叶子节点总数
int Count(BiTree T,int &count)
{
	if (T == NULL)
		return 1;
	int n = Count(T->lchild,count);
	int m = Count(T->rchild,count);
	if (n == 1 && m == 1)
		count++;
	return 0;
}
int main() {
	int count = 0;
	queue<BiTree> q;
	BiTree t = NULL;
	createBiTree(&t);
	Count(t, count);
	cout << "\n树的叶节点的个数为：" << count << endl;
	cout << "\n树的节点个数为：" << NodeCount(t) << endl;
	cout << "\n树的深度为：" << Depth(t) << endl;
	QueueTraverse(t, q);
	printf("\n\nPreOrder the tree is:");
	PreOrder(t);
	printf("\n\nInOrder the tree is:");
	InOrder(t);
	printf("\n\nPostOrder the tree is:");
	PostOrder(t);
	printf("\n\n先序遍历序列（非递归）:");
	Preorder_n(t);
	cout << "\n\n中序遍历序列（非递归）：";
	InOrderTraverse(t);
	cout << "\n\n后序遍历序列（非递归）：";
	PostOrderTraverse(t);
	release(t);
	return 0;
}
