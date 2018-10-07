#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int x[1200][1200];

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string a, b;
		cin >> a;
		b = a;
		reverse(b.begin(), b.end());
		int n = a.length();
		for (int i = 0; i <= n; i++)
			x[i][0]=0;
		for (int j = 0; j <= n; j++)
			x[0][j] = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i] == b[j])
					x[i+1][j+1] = x[i][j] + 1;
				else
					x[i+1][j+1] = max(x[i][j+1], x[i+1][j]);
			}
		}
		cout << n - x[n][n] << endl;
	}
	return 0;
}