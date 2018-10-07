#pragma once
#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef struct
{
	int *base;
	int *top;
	int stacksize;
}SqStack;
bool Init(SqStack &S);
bool Push(SqStack &S, int e);
bool Pop(SqStack &S, int &e);
bool GetTop(SqStack S, int &e);
bool Show(SqStack S);
