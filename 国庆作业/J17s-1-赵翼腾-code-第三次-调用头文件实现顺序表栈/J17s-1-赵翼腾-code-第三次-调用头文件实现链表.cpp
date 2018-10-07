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
	cout << "请输入入栈的个数：";
	cin >> n;
	int e;
	for (int i = 0; i < n; i++)
	{
		cin >> e;
		Push(S, e);
	}
	Show(S);
	cout << "删除栈顶元素" << endl;
	Pop(S, e);
	Show(S);
	cout << "请输入要添加的元素值：" << endl;

	cin >> e;
	Push(S, e);
	Show(S);
	return 0;
}


