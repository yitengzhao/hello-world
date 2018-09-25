#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
#define MAXSIZE 100


typedef struct
{
	int *base;
	int *top;
	int stacksize;
}SqStack;

bool Init(SqStack &S)
{
	S.base = new int[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
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
	cout << "�����";
	while (S.base != S.top)
	{
		cout << *--S.top<<" ";
	}
	cout<<endl;
	return 1;
}

int main()
{
	SqStack S;
	Init(S);
	int n;
	cout << "��������ջ�ĸ�����";
	cin >> n;
	int e;
	for (int i = 0; i < n; i++)
	{
		cin >> e;
		Push(S, e);
	}
	Show(S);
	cout<<"ɾ��ջ��Ԫ��"<<endl;
	Pop(S,e);
	Show(S);
	cout<<"������Ҫ��ӵ�Ԫ��ֵ��"<<endl; 

	cin>>e;
	Push(S,e);
	Show(S);
	return 0;
}
