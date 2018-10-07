#include"list_t.h"
#include"list_t.cpp" 
#include<iostream>
using namespace std;

int main()
{
	LinkList L;
	int n;
	cout << "请选择插入方式：\n1、尾插法。\n2、头插法。" << endl;
	cin >> n;
	switch (n)
	{
	case 1:
		int n;
		cout << "请输入插入元素的个数：" << endl;
		cin >> n;
		CreatList_R(L, n);
		break;
	case 2:
		int i;
		cout << "请输入插入元素的个数：" << endl;
		cin >> i;
		CreatList_R(L, i);
		break;
	default:
		cout << "ERROR!" << endl;
		return 0;
		break;
	}
	ListShow(L);
	cout << "请输入要插元素的位置i和值e:" << endl;
	int i, e;
	cin >> i >> e;
	ListInsert(L, e, i);
	ListShow(L);
	cout << "请输入想要删除元素的位置i：" << endl;
	cin >> i;
	ListDelete(L, i);
	ListShow(L);
}

