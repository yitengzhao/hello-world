#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;
	cout << "请输入杨辉三角的层数：";
	cin >> n;

	queue<int>q;
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	else if (n == 2)
	{
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	else
	{
		cout << 1 << endl;
		cout << 1 << " " << 1 << endl;
	}
	q.push(0);
	q.push(1);
	q.push(1);
	q.push(0);
	for (int i = 3; i <= n; i++)
	{
		int x, y;
		y = 1;
		while (y != 0)
		{
			x = q.front();
			q.pop();
			y = q.front();
			q.push(x + y);
		}
		q.push(0);
		queue<int>tmp = q;
		while (!tmp.empty())
		{
			if (tmp.front() != 0)
				cout << tmp.front() << " ";
			tmp.pop();
		}
		cout << endl;
	}
	return 0;
}
