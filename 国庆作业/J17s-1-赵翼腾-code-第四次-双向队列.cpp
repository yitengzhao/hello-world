#include<iostream>
#include<string>
#include<deque>
using namespace std;
int a[100];
bool Lin(deque<int>&dq,int e)
{
	dq.push_front(e);
	return true;
}
bool Rin(deque<int>&dq, int e)
{
	dq.push_back(e);
	return true;
}
bool Lout(deque<int>&dq)
{
	if (dq.empty())
	{
		return false;
	}
	dq.pop_front();
	return true;
}
bool Rout(deque<int>&dq)
{
	if (dq.empty())
	{
		return false;
	}
	dq.pop_back();
	return true;
}



int main()
{
	deque<int>dq;
	deque<int>::iterator it;
	int n;
	cin >> n;
	int n_ = n;
	int count = 0;
	while (n--)
	{
		string s;
		cin >> s;
		if (s == "LIN")
		{
			int e;
			cin >> e;
			Lin(dq, e);
		}
		else if (s == "RIN")
		{
			int e;
			cin >> e;
			Rin(dq, e);
		}
		else if (s == "LOUT")
		{
			if ((Lout(dq)) != true)
				a[count++] = n_-n;
		}
		else if (s == "ROUT")
		{
			if ((Rout(dq) )!= true)
				a[count++] = n_ - n;
		
		}
	}
//	show(dq);
	for (it = dq.begin(); it != dq.end(); it++)
		printf("%d ", *it);
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		cout << a[i] << " ERROR" << endl;
	}

	return 0;
}