#include<iostream>
using namespace std;
#define OK 1;
#define ERROR 0;

typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

int InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}
int EnQueue(LinkQueue &Q, int e)
{
	QueuePtr p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
int DeQueue(LinkQueue &Q, int &e)
{
	if (Q.front == Q.rear)
		return ERROR;
	QueuePtr p=new QNode;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
	return OK;
}

int GetHead(LinkQueue Q,int &e)
{
	if (Q.front != Q.rear)
	{
		e = Q.front->next->data;
		return OK;
	}
	else
		return ERROR;
}


int main()
{
	LinkQueue Q;
	int n;
	int flag = 0;
	cout << "1、初始化队列。\n2、在队尾插入一个新的元素。\n3、将队头元素删除。\n4、取队头元素的值。\n0、退出。\n";
	while (cin >> n)
	{
		switch (n)
		{
		case 1:

			flag = InitQueue(Q);
			cout << "初始化完成！" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
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
				flag2 = EnQueue(Q, e);
				if (flag == 1)
					cout << "插入完成！" << endl;
				else
					cout << "插入失败" << endl;
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
				int flag3 = 0;
				flag3 = DeQueue(Q, e);
				if (flag3 == 1)
					cout << "已删除e:" << e << endl;
				else
					cout << "删除错误！" << endl;
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
		cout << "1、初始化队列。\n2、在队尾插入一个新的元素。\n3、将队头元素删除。\n4、取队头元素的值。\n0、退出。\n";
	}
	return 0;
}