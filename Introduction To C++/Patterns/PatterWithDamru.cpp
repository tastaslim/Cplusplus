#include <iostream>
using namespace std;
int main()
{
    bool k = true;
    int n;
    int m = 1;
    int l = 1;
    cin >> n;
    if (n == 1)
    {
        cout << 1
             << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            if (j >= i && j <= 2 * n - i && k)
            {
                cout << m;
                m++;
                k = false;
            }
            else
            {
                cout << " ";
                k = true;
            }
        }
        if (i != n)
            cout << endl;
        m = i + 1;
    }

    m = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            if (j >= n + 1 - i && j <= n - 1 + i && k && i != 1)
            {
                cout << m;
                m++;
                k = false;
            }
            else
            {
                cout << " ";
                k = true;
            }
        }
        cout << endl;
        m = n - i;
    }
    return 0;
}