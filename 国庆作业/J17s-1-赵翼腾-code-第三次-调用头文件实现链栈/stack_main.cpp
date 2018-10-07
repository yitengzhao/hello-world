#include"stack_t.h"
#include<iostream>
using namespace std;

int main()
{
	LinkStack S;
	Creat(S);
	Show(S);
	int e;
	cout << "输入插入的元素" << endl;
	cin >> e;

	Push(S, e);
	Show(S);
	cout << "下一个操作为删除" << endl;

	cout << "删除最开始的一个元素" << endl;
	Pop(S, e);
	cout << "删除的元素为:" << e << endl;
	Show(S);
}
