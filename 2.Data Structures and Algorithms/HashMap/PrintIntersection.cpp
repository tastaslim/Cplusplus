#include <bits/stdc++.h>
using namespace std;
void printIntersection(int *input1, int n, int *input2, int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[input1[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[input2[i]] > 0)
        {
            cout << input2[i] << " ";
            mp[input2[i]]--;
        }
    }
}

int main()
{
    int n;
    int input1[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input1[i];
    }
    int m;
    int input2[100000];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> input2[i];
    }
    printIntersection(input1, n, input2, m);
    return 0;
}
