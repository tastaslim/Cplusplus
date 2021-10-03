#include <bits/stdc++.h>
using namespace std;
int highestFrequency(int *input, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[input[i]]++;
    }

    int max = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[input[i]] > max)
        {
            max = mp[input[i]];
            ans = input[i];
        }
    }
    return ans;
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
    int maxKey = highestFrequency(input, n);
    cout << maxKey;
    return 0;
}
