#include<iostream>
#include<cstdlib>
#include<cmath> 
using namespace std;
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue &Q)
{
	Q.base = new int[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

int QueueLength(SqQueue Q)
{
	return(Q.rear - Q.front + MAXQSIZE)&MAXQSIZE;
}

int EnQueue(SqQueue &Q, int e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

int DeQueue(SqQueue &Q, int &e)
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

int GetHead(SqQueue Q,int &e)
{
	if (Q.front != Q.rear)
	{
		e = Q.base[Q.front];
		return OK;
	}
	else
		return ERROR;
}

int main()
{
	SqQueue Q;
	int n;
	int flag=0;
	cout << "1、初始化队列。\n2、求队列的长度。\n3、在队尾插入一个新的元素。\n4、将队头元素删除。\n5、取队头元素的值。\n0、退出。\n";
	while (cin >> n)
	{
		switch (n)
		{
		case 1:

			flag=InitQueue(Q);
			cout << "初始化完成！" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			if (flag==0)
			{
				cout << "Error:未初始化队列" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				int e;
				e = QueueLength(Q);
				cout << "队列的长度为：";
				cout << e << endl;
				system("pause");
				system("cls");
			}
			break;
		case 3:
			if (flag == 0)
			{
				cout << "Error:未初始化队列" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				int e;
				cout << "请输入一个数：";
				cin >> e;
				int flag2 = 0;
				flag2=EnQueue(Q, e);
				if (flag == 1)
					cout << "插入完成！" << endl;
				else
					cout << "插入失败" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 4:
			if (flag == 0)
			{
				cout << "Error:未初始化队列" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				int e;
				int flag3 = 0;
				flag3=DeQueue(Q, e);
				if (flag3 == 1)
					cout << "已删除e:" << e << endl;
				else
					cout << "删除错误！" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 5:
			if (flag == 0)
			{
				cout << "Error:未初始化队列" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				int a;
				if (GetHead(Q, a) == 1)
					cout << "队头元素的值为：" << a << endl;
				else
					cout << "ERROR!" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 0:
			return 0;

		}
		cout << "1、初始化一个队列。\n2、求队列的长度。\n3、在队尾插入一个新的元素。\n4、将队头元素删除。\n5、取队头元素的值。\n0、退出。\n";
	}
	return 0;
}
