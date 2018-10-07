#include"list_t.h"
#include<iostream>
#include<cstdlib>
using namespace std;

int Initlist(LinkList &L)
{//初始化
	L = new LNode;
	L->next = NULL;
	return OK;
}

//插入
int ListInsert(LinkList &L, int e, int i)
{
	LinkList p = L;
	int j = 0;
	//	if(i==0)
	//	return ERROR;
		//Point
	while (p && (j < i - 1))
	{
		p = p->next;
		j++;
	}

	if (!p || j > i - 1)
		return ERROR;
	//Point

	//LinkList s = p;
	LinkList s = new LNode;
	s->data = e;

	s->next = p->next;
	p->next = s;
	return OK;

}

//取值
int GetElem(LinkList L, int i, int &e)
{
	LinkList p = L;
	int j = 0;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	return OK;
}

//查找
LinkList LocateElem(LinkList L, int e)
{
	LinkList p = L->next;
	//while (p != NULL)
	//{
	//	if (p->data == e)
	//		return p;
	//}
	//return NULL;
	while (p&&p->data != e)
		p = p->next;
	return p;
}

//删除
int ListDelete(LinkList &L, int i)
{
	LinkList p = L;
	int j = 0;

	//point
	while (p->next&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)
		return ERROR;
	//point

	LinkList q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}

void CreatList_H(LinkList &L, int n)
{
	L = new LNode;
	L->next = NULL;


	for (int i = 0; i < n; i++)
	{
		LinkList p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}
void CreatList_R(LinkList &L, int n)
{
	L = new LNode;
	L->next = NULL;
	LinkList r = L;
	for (int i = 0; i < n; i++)
	{
		LinkList p = new LNode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

int ListShow(LinkList &L)
{
	LinkList p = L->next;
	if (p == NULL)
	{
		cout << "链表内没有数据" << endl;
		return 0;
	}
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return 1;
}
