#include <bits/stdc++.h>
using namespace std;
void removeDuplicates(int *input, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[input[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[input[i]] > 0)
        {
            cout << input[i] << " ";
            mp[input[i]] = 0;
        }
    }
}

int main()
{
    int n;
    int input[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    removeDuplicates(input, n);
    return 0;
}
