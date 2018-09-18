#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef struct 
{
	int *base;
	int *top;
	int stacksize;
}SqStack;

//��ʼ��
int InitStack(SqStack &S)
{
	S.base = new int[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

//��ջ
int Push(SqStack &S, int e)
{
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}

//��ջ
int Pop(SqStack &S, int &e)
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}

int GetTop(SqStack S)
{
	if (S.top != S.base)
		return *(S.top - 1);
}

int main()
{
/*
*/
	return 0;
}