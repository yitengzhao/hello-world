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
	cout << "1����ʼ�����С�\n2������еĳ��ȡ�\n3���ڶ�β����һ���µ�Ԫ�ء�\n4������ͷԪ��ɾ����\n5��ȡ��ͷԪ�ص�ֵ��\n0���˳���\n";
	while (cin >> n)
	{
		switch (n)
		{
		case 1:

			flag=InitQueue(Q);
			cout << "��ʼ����ɣ�" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			if (flag==0)
			{
				cout << "Error:δ��ʼ������" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				int e;
				e = QueueLength(Q);
				cout << "���еĳ���Ϊ��";
				cout << e << endl;
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
				cout << "������һ������";
				cin >> e;
				int flag2 = 0;
				flag2=EnQueue(Q, e);
				if (flag == 1)
					cout << "������ɣ�" << endl;
				else
					cout << "����ʧ��" << endl;
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
				int e;
				int flag3 = 0;
				flag3=DeQueue(Q, e);
				if (flag3 == 1)
					cout << "��ɾ��e:" << e << endl;
				else
					cout << "ɾ������" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 5:
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
		cout << "1����ʼ��һ�����С�\n2������еĳ��ȡ�\n3���ڶ�β����һ���µ�Ԫ�ء�\n4������ͷԪ��ɾ����\n5��ȡ��ͷԪ�ص�ֵ��\n0���˳���\n";
	}
	return 0;
}
