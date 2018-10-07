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
	cout << "1����ʼ�����С�\n2���ڶ�β����һ���µ�Ԫ�ء�\n3������ͷԪ��ɾ����\n4��ȡ��ͷԪ�ص�ֵ��\n0���˳���\n";
	while (cin >> n)
	{
		switch (n)
		{
		case 1:

			flag = InitQueue(Q);
			cout << "��ʼ����ɣ�" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			if (flag == 0)
			{
				cout << "Error:δ��ʼ������" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				int e;
				cout << "������һ������";
				cin >> e;
				int flag2 = 0;
				flag2 = EnQueue(Q, e);
				if (flag == 1)
					cout << "������ɣ�" << endl;
				else
					cout << "����ʧ��" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 3:
			if (flag == 0)
			{
				cout << "Error:δ��ʼ������" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				int e;
				int flag3 = 0;
				flag3 = DeQueue(Q, e);
				if (flag3 == 1)
					cout << "��ɾ��e:" << e << endl;
				else
					cout << "ɾ������" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 4:
			if (flag == 0)
			{
				cout << "Error:δ��ʼ������" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				int a;
				if (GetHead(Q, a) == 1)
					cout << "��ͷԪ�ص�ֵΪ��" << a << endl;
				else
					cout << "ERROR!" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 0:
			return 0;

		}
		cout << "1����ʼ�����С�\n2���ڶ�β����һ���µ�Ԫ�ء�\n3������ͷԪ��ɾ����\n4��ȡ��ͷԪ�ص�ֵ��\n0���˳���\n";
	}
	return 0;
}