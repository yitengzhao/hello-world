#include<iostream>
using namespace std;

typedef struct StackNode
{
	int data;
	struct StackNode *next;
 }StackNode,*LinkStack;

//初始化
bool InitStack(LinkStack &S)
{
	S = NULL;
	return true;
}

//入栈
bool Push(LinkStack &S, int e)
{
	LinkStack p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return true;
}

//出栈
bool Push(LinkStack &S, int &e)
{
	if (S == NULL)
		return false;
	e = S->data;
	LinkStack p = S;
	S = S->next;
	delete p;
	return true;

}

//取栈顶元素
bool GetTop(LinkStack S, int &e)
{
	if (S == NULL)
		return false;
	e = S->data;
	return true;
}