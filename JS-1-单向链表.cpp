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

//��ʼ��
int Initlist(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}

//����
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

//ȡֵ
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

//����
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

//ɾ��
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

//���򴴽�����
void CreatList_H(LinkList &L)
{

	int n;
	cout << "���򴴽���������������ĳ��ȣ�";
	cin >> n;
	L = new LNode;
	L->next = NULL;
	cout << "��������������" << endl;

	for (int i = 0; i < n; i++)
	{
		LinkList p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

//���򴴽�����
void CreatList_R(LinkList &L)
{
	int n;
	cout << "���򴴽���������������ĳ���:";
	cin >> n;
	cout << "��������������" << endl;
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

//�������
int show(LinkList &L)
{
	LinkList p = L->next;
	if (p == NULL)
	{
		cout << "������û������" << endl;
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
	cout << "����������Ҫɾ��������";
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
		cout << "�������޴���" << endl;
		return 0;
	}
	if (p->next == NULL)
	{
		q->next = NULL;
		delete p;

		cout << "��ɾ��" << endl;
		return 1;
	}
	else
	{
		q->next = p->next;
		delete p;
		cout << "��ɾ��" << endl;
		return 1;
	}
}

//�ж��Ƿ�Ϊ��
int isempty(LinkList &L)
{
	if (L->next == NULL)
	{
		cout << "����Ϊ��" << endl;
		return 0;
	}
	else
	{
		cout << "�������Ԫ��" << endl;
		return 1;
	}
}

int main()
{
	
	int j;
	cout << "��ѡ����еĲ�����" << endl;
	cout << "1��������������ݣ��ҵ���Ӧ�Ĵ洢��Ԫ��ɾ��������ʾ�������е�����" << endl;
	cout << "2���ϲ���������" << endl;
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