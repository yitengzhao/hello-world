#include"list_t.h"
#include"list_t.cpp" 
#include<iostream>
using namespace std;

int main()
{
	LinkList L;
	int n;
	cout << "��ѡ����뷽ʽ��\n1��β�巨��\n2��ͷ�巨��" << endl;
	cin >> n;
	switch (n)
	{
	case 1:
		int n;
		cout << "���������Ԫ�صĸ�����" << endl;
		cin >> n;
		CreatList_R(L, n);
		break;
	case 2:
		int i;
		cout << "���������Ԫ�صĸ�����" << endl;
		cin >> i;
		CreatList_R(L, i);
		break;
	default:
		cout << "ERROR!" << endl;
		return 0;
		break;
	}
	ListShow(L);
	cout << "������Ҫ��Ԫ�ص�λ��i��ֵe:" << endl;
	int i, e;
	cin >> i >> e;
	ListInsert(L, e, i);
	ListShow(L);
	cout << "��������Ҫɾ��Ԫ�ص�λ��i��" << endl;
	cin >> i;
	ListDelete(L, i);
	ListShow(L);
}

