#include<iostream>
using namespace std;


typedef struct StackNode
{
	int data;
	struct StackNode *next;
}StackNode, *LinkStack;

char a[16];
int a1[16];
void sss()
{
	char z = 'A';
	for (int i = 10; i <= 16; i++)
	{
		a[i] = z;
		z++;
	}
}



bool Init(LinkStack &S)
{
	S = NULL;
	return 1;
}

bool Push(LinkStack &S, int e)
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
		if(p->data<=9)
			cout << p->data;
		else if(p->data>=10)
		{
			cout << a[p->data];
		}
		else if(p->data<0&&p->data>=-9)
		{
			//cout << -p->data;
		}
		else if (p->data <= -10)
		{
			//cout << a[-p->data];
		}
		p = p->next;
	}
	return 1;
}


int main()
{
	sss();

	int n;
	int k;


	/*cout << "请输入一个十进制数n：" << endl;
	cin >> n;
	cout << "请输入要转换的进制数k：" << endl;
	cin >> k;*/
	while (cin >> n >> k)
	{
		LinkStack S;
		Init(S);
		if (n < 0)
		{
			cout << "-";
			n = -n;
		}
		//int a;//十进制的整数部分
		//a = (int)n;
		//double b = n - a;//十进制的小数部分
		//n = -n;
		while (n != 0)
		{

			Push(S, n%k);
			n = n / k;
		}
		Show(S);
		
		cout << endl;
	}
	return 0;
}