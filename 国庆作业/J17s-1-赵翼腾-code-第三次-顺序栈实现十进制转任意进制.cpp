#include<iostream>
using namespace std;
#define MAXSIZE 1000

char a[16];
void sss()
{
	char z = 'A';
	for (int i = 10; i <= 16; i++)
	{
		a[i] = z;
		z++;
	}
}
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
	while (S.base != S.top)
	{
		cout << *--S.top;
	}
	return 1;
}


int main()
{
	sss();
	SqStack S;
	Init(S);
	double n;
	int k;


	cout << "请输入一个十进制数n：" << endl;
	cin >> n;
	cout << "请输入要转换的进制数k：" << endl;
	cin >> k;

	if (n < 0)
	{
		cout << "-";
		n = -n;
	}
	int a;//十进制的整数部分
	a = (int)n;
	double b = n - a;//十进制的小数部分
	while (a != 0)
	{

		Push(S, a%k);
		a = a / k;
	}
	Show(S);
	if (b != 0)
		cout << ".";
	for (int i = 0; i < 50; i++)
	{
		if (b == 0)
			break;
		b = b * k;
		cout << int(b);
		b = b - int(b);

	}
	cout << endl;
	return 0;
}
