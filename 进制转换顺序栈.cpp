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
	cout << "输出：";
	while (S.base != S.top)
	{
		cout << *--S.top ;
	}
	return 1;
}

int main()
{
	SqStack S;
	Init(S);
	int n,k;
	cout << "请输入十进制数n："<<endl;
	cin >> n;
	cout << "请输入要转换的进制k:" << endl;
	cin >> k;

	while (n != 0)
	{
		Push(S, n%k);
		n = n / k;
	}
	Show(S);
	return 0;
}