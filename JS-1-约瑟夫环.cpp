#include<iostream>
#include<cstdio>
using namespace std;
int na[100];
typedef struct child
{
	int num;
	int count;
	struct child *next;
}child, *List;

void creat(List &L, int n)
{
	L = new child;
	L->next = NULL;
	List q = L;
	int k = 1;
	//	cout << "请输入n个数,代表这n个孩子的座位序号" << endl;
	for (int i = 0; i < n; i++)
	{
		List p = new child;
		p->num = k;
		k++;
		p->count = 0;
		q->next = p;
		p->next = L->next;
		q = q->next;
	}
}

List getm(List L, int m)
{
	List p = L;
	for (int i = 0; i < m; i++)
	{
		p = p->next;
	}
	return p;
}


int main()
{
	List L;
	int n;
	cout << "请输入n:";
	cin >> n;
	creat(L, n);

	int m;
	cout << "请输入m:";
	cin >> m;

	int k;
	cout << "请输入K：";
	cin >> k;




	List p = getm(L, m);
	if (p == NULL)
		return 0;
	int counter = 1;
	int i = 0;
	int sss = 0;
	while (counter <= n)
	{
		//	p = p->next;
		if (p->count == 0)
			i++;
		if (i == k)
		{
			p->count = counter;
			counter++;
			na[sss] = p->num;
			sss++;
			i = 0;
		}
		p = p->next;
	}
	//	show(L, n);
	for (int i = 0; i < n; i++)
		cout << na[i] << " ";
}