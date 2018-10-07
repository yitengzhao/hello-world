#include<iostream>
#include"stack_t.h"
using namespace std;



bool Init(SqStack &S)
{
	S.base = new int[MAXSIZE];
	if (!S.base)
		return 0;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return 1;
}

bool Push(SqStack &S, int e)
{
	if (S.top - S.base == S.stacksize)
		return 0;
	*S.top++ = e;
	return 1;
}

bool Pop(SqStack &S, int &e)
{
	if (S.top == S.base)
		return 0;
	e = *--S.top;
	return 1;
}

bool GetTop(SqStack S, int &e)
{
	if (S.top == S.base)
		return 0;
	e = *(S.top - 1);
	return 1;
}

bool Show(SqStack S)
{
	if (S.base == S.top)
		return 0;
	cout << "Êä³ö£º";
	while (S.base != S.top)
	{
		cout << *--S.top << " ";
	}
	cout << endl;
	return 1;
}

