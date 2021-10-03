#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i, j;
    int sp = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        for (j = 1; j <= sp; j++)
            cout << " ";
        sp++;
        for (j = 1; j <= 2 * (n - i) - 1; j++)
            cout << "*";
        cout << endl;
    }
    sp = n - 1;
    for (int i = 1; i <= n; ++i)
    {
        for (j = 1; j <= sp; j++)
            cout << " ";
        sp--;
        for (j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}