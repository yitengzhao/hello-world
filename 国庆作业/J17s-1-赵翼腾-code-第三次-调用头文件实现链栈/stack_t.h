#pragma once
#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef struct StackNode
{
	int data;
	struct StackNode *next;
}StackNode,*LinkStack;

bool init(LinkStack &S);
bool Push(LinkStack &S,int e);
bool Pop(LinkStack &S, int &e);
bool GetTop(LinkStack &S, int &e);
bool Creat(LinkStack &S);
bool Show(LinkStack &S);