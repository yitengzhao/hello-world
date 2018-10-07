#pragma once
#define OK 1
#define ERROR 0

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

int InitList(LinkList &L);
int ListInsert(LinkList &L, int e, int i);
int GetElem(LinkList L, int i, int &e);
LinkList LocateElem(LinkList L, int e);
int ListDelete(LinkList &L, int i);
void CreateList_H(LinkList &L, int n);
void CreatList_R(LinkList &L, int n);
int ListShow(LinkList &L);