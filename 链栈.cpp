#include<iostream>
using namespace std;

typedef struct StackNode
{
	int data;
	struct StackNode *next;
 }StackNode,*LinkStack;

//��ʼ��
bool InitStack(LinkStack &S)
{
	S = NULL;
	return true;
}

//��ջ
bool Push(LinkStack &S, int e)
{
	LinkStack p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return true;
}

//��ջ
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

//ȡջ��Ԫ��
bool GetTop(LinkStack S, int &e)
{
	if (S == NULL)
		return false;
	e = S->data;
	return true;
}