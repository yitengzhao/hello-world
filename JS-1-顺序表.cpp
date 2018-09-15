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


//初始化线性表
int initList(List &L)
{
	L.data = new int[MAXSIZE];
	if (!L.data)
		return 0;
	L.length = 0;
	return 1;
}

//插入元素
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

//取表中第i个元素
int find(List L, int i, int &e)
{
	if (i<1 || i>L.length + 1)
		return 0;
	e = L.data[i - 1];
	return 1;
}

//定位函数
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

//删除
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

//显示
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
		cout << "顺序表已存在！" << endl;
		return 0;
	}
	int n;
	cout << "请输入顺序表的长度：";
	cin >> n;
	cout << "依次输入顺序表的值" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> L.data[i];
		L.length++;
	}
	return 1;
}

//判断顺序表是否为空
int isempty(List L)
{
	if (L.length == 0)
	{
		cout << "顺序表为空" << endl;
		return 0;
	}
	else
	{
		cout << "顺序表不为空" << endl;
		return 1;
	}
}

int task(List &L)
{
	if (L.length == 0)
		return 0;
	int n;
	cout << "请输入想要删除的数：";
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
	cout << "附注：其他函数均以实现，只调用了第四部分内容：根据输入的数据，找到相应的存储单元并删除，并显示表中所有的数据" << endl;
	creat(L);
	task(L);
	return 0;
}