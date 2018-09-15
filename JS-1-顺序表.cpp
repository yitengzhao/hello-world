#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define MAXSIZE 50
typedef struct
{
	int *data;
	int length;
}List;


//��ʼ�����Ա�
int initList(List &L)
{
	L.data = new int[MAXSIZE];
	if (!L.data)
		return 0;
	L.length = 0;
	return 1;
}

//����Ԫ��
int insert(List &L, int i, int e)
{
	if (i<1 || i>L.length + 1)
		return 0;
	for (int j = L.length - 1; j >= i - 1; j--)
		L.data[j + 1] = L.data[j];
	L.data[i - 1] = e;
	L.length++;
	return 0;
}

//ȡ���е�i��Ԫ��
int find(List L, int i, int &e)
{
	if (i<1 || i>L.length + 1)
		return 0;
	e = L.data[i - 1];
	return 1;
}

//��λ����
int locate(List L, int &i, int e)
{
	for (int j = 0; j < L.length; j++)
	{
		if (e == L.data[j])
		{
			i = j+1;
			return 1;
		}
	}
	return 0;
}

//ɾ��
int erase(List &L, int i, int &e)
{
	if (i<1 || i>L.length)
		return 0;
	e = L.data[i - 1];
	for (int j = i - 1; j < L.length - 1; j++)
		L.data[j] = L.data[j + 1];
	L.length--;
	return 1;
}

//��ʾ
int show(List &L)
{
	if (L.length == 0)
	{
		cout << "None" << endl;
		return 0;
	}
	for (int i = 0; i < L.length; i++)
	{
		cout << L.data[i] << " ";
	}
	return 1;
}

int creat(List &L)
{
	if (L.length != 0)
	{
		cout << "˳����Ѵ��ڣ�" << endl;
		return 0;
	}
	int n;
	cout << "������˳���ĳ��ȣ�";
	cin >> n;
	cout << "��������˳����ֵ" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> L.data[i];
		L.length++;
	}
	return 1;
}

//�ж�˳����Ƿ�Ϊ��
int isempty(List L)
{
	if (L.length == 0)
	{
		cout << "˳���Ϊ��" << endl;
		return 0;
	}
	else
	{
		cout << "˳���Ϊ��" << endl;
		return 1;
	}
}

int task(List &L)
{
	if (L.length == 0)
		return 0;
	int n;
	cout << "��������Ҫɾ��������";
	cin >> n;
	int i;
	locate(L, i, n);
	erase(L, i, n);
	show(L);
	return 1;
}

int main()
{
	List L;
	initList(L);
	cout << "��ע��������������ʵ�֣�ֻ�����˵��Ĳ������ݣ�������������ݣ��ҵ���Ӧ�Ĵ洢��Ԫ��ɾ��������ʾ�������е�����" << endl;
	creat(L);
	task(L);
	return 0;
}