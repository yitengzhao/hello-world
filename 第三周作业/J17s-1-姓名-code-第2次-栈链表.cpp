#include<iostream>
using namespace std;


typedef struct StackNode
{
	int data;
	struct StackNode *next;
}StackNode,*LinkStack;

bool init(LinkStack &S)
{
	S = NULL;
	return 1;
}

bool Push(LinkStack &S,int e)
{
	LinkStack p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return 1;
}

bool Pop(LinkStack &S, int &e)
{
	if (S == NULL)
		return 0;
	e = S->data;
	LinkStack p = S;
	S = S->next;
	delete p;
	return 1;
}

bool GetTop(LinkStack &S, int &e)
{
	if (S == NULL)
		return 0;
	e = S->data;
	return 1;
}

bool Creat(LinkStack &S)
{
	S = NULL;
	int n;
	cout << "请输入入栈元素的个数：";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		LinkStack p = new StackNode;
		cin >> p->data;
		p->next = S;
		S = p;
	}
	return 1;
}

bool Show(LinkStack &S)
{
	LinkStack p = S;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	return 1;
}


int main()
{
	LinkStack S;
	Creat(S);
	Show(S);
}