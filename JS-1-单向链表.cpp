#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define OK 1
#define ERROR 0

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

//初始化
int Initlist(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}

//插入
int ListInsert(LinkList &L, int e, int i)
{
	LinkList p = L;
	int j = 0;

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

//逆序创建链表
void CreatList_H(LinkList &L)
{

	int n;
	cout << "逆序创建链表，请输入链表的长度：";
	cin >> n;
	L = new LNode;
	L->next = NULL;
	cout << "请依次输入数据" << endl;

	for (int i = 0; i < n; i++)
	{
		LinkList p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

//正序创建链表
void CreatList_R(LinkList &L)
{
	int n;
	cout << "正序创建链表，请输入链表的长度:";
	cin >> n;
	cout << "请依次输入数据" << endl;
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

//输出链表
int show(LinkList &L)
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
	return 1;
}

int task1(LinkList &L)
{
	int e;
	cout << "请输入你需要删除的数：";
	cin >> e;
	LinkList p = L->next;
	LinkList q = L;
	while (p&&p->data != e)
	{
		q = p;
		p = p->next;
	}
	//while (p&&p->data != e)
	//	p = p->next;
	if (p == NULL)
	{
		cout << "链表中无此数" << endl;
		return 0;
	}
	if (p->next == NULL)
	{
		q->next = NULL;
		delete p;

		cout << "已删除" << endl;
		return 1;
	}
	else
	{
		q->next = p->next;
		delete p;
		cout << "已删除" << endl;
		return 1;
	}
}

//判断是否为空
int isempty(LinkList &L)
{
	if (L->next == NULL)
	{
		cout << "链表为空" << endl;
		return 0;
	}
	else
	{
		cout << "链表存在元素" << endl;
		return 1;
	}
}

int main()
{
	
	int j;
	cout << "请选择进行的操作：" << endl;
	cout << "1、根据输入的数据，找到相应的存储单元并删除，并显示表中所有的数据" << endl;
	cout << "2、合并连个链表" << endl;
	cin >> j;
	switch (j)
	{
	case 1:
		LinkList L;
		CreatList_R(L);
		task1(L);
		show(L);
		break;
	case 2:
		LinkList L1;
		LinkList L2;
		CreatList_H(L1);
		CreatList_R(L2);
		LinkList p = L1->next;
		LinkList q = L2->next;
		LinkList p2 = L1;
	//	LinkList q2 = L2->next;
		while (q)
		{
			while (p&&q->data > p->data)
			{
				p2 = p;
				p = p->next;
				
			}
			if (p == NULL)
			{
				p2->next = q;
				show(L1);
				return 0;
			}
			if (q->data == p->data)
			{
				q = q->next;
	//			continue;
			}
			else
			{
				
				LinkList q2 = q;
				q = q->next;
				q2->next = p;
				p2->next = q2;
				p2 = p2->next;
			}
		}
		show(L1);
		break;
	}

}