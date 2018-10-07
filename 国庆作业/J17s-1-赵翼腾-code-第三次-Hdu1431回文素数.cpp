#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

#define maxn 9989899+1
bool isPrime[maxn + 1];
int ans[900];

void getPrime()
{
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i < maxn; i++)
	{
		if (isPrime[i])
		{
			for (int j = i + i; j < maxn; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

bool isHuiwen(int n)
{
	int sum = 0;
	int nn = n;
	while (n != 0)
	{
		sum = sum * 10 + n % 10;
		n = n / 10;
	}
	if (sum == nn)
		return true;
	else
		return false;
}

int main()
{
	getPrime();
	int a, b;
	int k = 0;
	for (int i = 2; i < maxn; i++)
	{
		if (isPrime[i] && isHuiwen(i))
			ans[k++] = i;
	}
	while (cin >> a >> b)
	{
		for (int i = 0; i <= k; i++)
		{
			if (ans[i] < a)
				continue;
			else if (ans[i] > b)
				break;
			else
				cout << ans[i] << endl;
		}
		cout << endl;
	}
	return 0;
}