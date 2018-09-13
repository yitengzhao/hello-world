#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0

typedef struct DulNode
{
	int data;
	struct DulNode *prior;
	struct DulNode *next;
}DuLNode,*DuLinkList;

int Init(DuLinkList &L)
{
	L = new DulNode;
	if (!L)
		return ERROR;
	L->next = NULL;
	L->prior = NULL;
	return OK;
}

void add(DuLinkList &L)
{
	int n;
	cout << "请输入链表的长度" << endl;
	cin >> n;
	int e;
	DuLinkList p = L;
	for (int i = 0; i < n; i++)
	{
		cin >> e;
		DuLinkList l = new DulNode;
		l->data = e;
		p->next = l;
		l->prior = p;
		l->next = NULL;
		p = l;
	}
}

DuLinkList GetElem_Dul(DuLinkList L, int i,int &e)
{
	DuLinkList p = L;
	int j = 0;
	while (p = p->next)
	{
		j++;
		if (j == i)
		{
			e = p->data;
			return p;
		}
	}
	return NULL;
}


int ListInsert_Dul(DuLinkList &L, int i, int e)
{
	DuLinkList p;
	int e2=0;
	if ( !(p = GetElem_Dul(L, i,e2)  ))
		return ERROR;
	DuLinkList s = new DulNode;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

int ListDelete_Dul(DuLinkList &L, int i)
{

	DuLinkList p;
	int e2 = 0;
	if (!(p = GetElem_Dul(L, i, e2)))
		return ERROR;
	p->prior->next = p->next;
	//自己加的 
	if (p->next == NULL)
	{
		delete p;
		return OK;
	}
	//
	p->next->prior = p->prior;
	delete p;
	return OK;
}

int main()
{
	DuLinkList L;
	Init(L);
	add(L);
//	ListInsert_Dul(L, 3, 3);
	ListDelete_Dul(L, 1);
//	int n;
//	GetElem_Dul(L, 1, n);

}