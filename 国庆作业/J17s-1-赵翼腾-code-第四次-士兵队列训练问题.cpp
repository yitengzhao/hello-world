#include<iostream>
#include<vector>
using namespace std;

//int a[5500];
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int N;
		cin >> N;
		vector<int> a;
		vector<int>::iterator it;
		for (int i = 1; i <= N; i++)
		{
			a.push_back(i);
		}

		int count1=1;
	//	int count2=1;
		while (a.size() > 3)
		{
			if (count1 % 2 != 0)
			{
				int count3 = 1;
				for (it = a.begin(); it != a.end(); it++)
				{
					if (count3 % 2 == 0)
					{
						it=a.erase(it);
						it--;
					}
					count3++;
				}
			}
			else
			{
				int count2 = 1;
				for (it = a.begin(); it != a.end(); it++)
				{
					if (count2 % 3 == 0)
					{
						it=a.erase(it);
						it--;
					}
					count2++;
				}
			}
			count1++;
		}

		for (it = a.begin(); it != a.end(); it++)
		{
			if (it != a.begin())
				cout << " ";
			cout << *it;
		}
		cout << endl;
	}
}