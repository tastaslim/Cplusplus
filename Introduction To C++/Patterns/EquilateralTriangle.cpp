#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if (j >= n + 1 - i && j <= n - 1 + i)
			{
				if (j == n + 1 - i || j == n - 1 + i || i == n && i != 2)
					cout << "*";
				else
					cout << "+";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}