#include<iostream>
#include<stack>
#include<string>
using namespace std;


void push(stack<int> &s1, stack<int> &s2,int e)
{
	s1.push(e);
}
void pop(stack<int> &s1, stack<int> &s2,int &e)
{
	if (s1.empty())
	{
		e = -1;
		return;
	}
	while (!s1.empty())
	{
		int t = s1.top();
		s2.push(t);
		s1.pop();
	}
	e = s2.top();
	s2.pop();
	while (!s2.empty())
	{
		int t = s2.top();
		s1.push(t);
		s2.pop();
	}
}
int main()
{
	int n;
	stack<int>s1;
	stack<int>s2;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (s == "PUSH")
		{
			int e;
			cin >> e;
			push(s1, s2, e);
		}
		else if(s=="POP")
		{
			int e;
			pop(s1, s2, e);
			cout << e << endl;
		}

	}
}