#include"stack_t.h"
#include"stack_t.cpp"
#include<iostream>
using namespace std;

int main()
{
	LinkStack S;
	Creat(S);
	Show(S);
	int e;
	cout << "��������Ԫ��" << endl;
	cin >> e;

	Push(S, e);
	Show(S);
	cout << "��һ������Ϊɾ��" << endl;

	cout << "ɾ���ʼ��һ��Ԫ��" << endl;
	Pop(S, e);
	cout << "ɾ����Ԫ��Ϊ:" << e << endl;
	Show(S);
	
}
