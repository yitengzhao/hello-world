#include<iostream>
#include<stack>
using namespace std;
class Statement
{
public:
	Statement(){}
	Statement(int n, char a, char b, char c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->n = n;
	}
	char a, b, c;
	int n;
};

void hanoi(int n, char a, char b, char c)
{
	stack <Statement> S;
	S.push(Statement(n, a, b, c));
	while (!S.empty())
	{
		Statement St = S.top();
		S.pop();
		n = St.n;
		a = St.a;
		b = St.b;
		c = St.c;

		if (n == 1)
		{
			cout << "从" << St.a << "到" << St.c << endl;
		}
		else
		{
			S.push(Statement(n - 1, b, a, c));
			S.push(Statement(1, a, b, c));
			S.push(Statement(n - 1, a, c, b));
		}
	}
}

int main()
{
	int n;
	cout << "请输入n:";
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}