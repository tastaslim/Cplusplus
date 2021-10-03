#include <bits/stdc++.h>
using namespace std;
// O(2^n) approach
// int factorial(int n)
// {
//     if (n == 0)
//         return 1;
//     return n * factorial(n - 1);
// }

// O(n) approach

int factorial(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 1;
    for (int i = 1; i <= n; i++)
        arr[i] = i;

    int mul = 1;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i * arr[i - 1];
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    int ans = factorial(n);
    cout << ans << endl;
    return 0;
}