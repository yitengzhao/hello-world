#include<iostream>
#include<cstdlib>
#include<cmath>
#include"stack_t.h"
#include"stack_t.cpp" 
using namespace std;

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
	cout << "ɾ��ջ��Ԫ��" << endl;
	Pop(S, e);
	Show(S);
	cout << "������Ҫ��ӵ�Ԫ��ֵ��" << endl;

	cin >> e;
	Push(S, e);
	Show(S);
	return 0;
}


