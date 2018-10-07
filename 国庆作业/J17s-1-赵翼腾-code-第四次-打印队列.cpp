#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		queue<int>q;
		priority_queue<int>pq;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			q.push(t);
			pq.push(t);
		}
		while (1)
		{
			int x;
			x = q.front();
			q.pop();
			if (m == 0)
			{
				if (x != pq.top())
				{
					q.push(x);
					m = q.size() - 1;
				}
				else
					break;
			}
			else
			{
				m--;
				if (x != pq.top())
				{
					q.push(x);
				}
				else
					pq.pop();
			}
		}
		cout <<n-q.size() << endl;


	}
	return 0;
}