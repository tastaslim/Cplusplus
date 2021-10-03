#include <bits/stdc++.h>
using namespace std;
void pairSum(int *input, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[input[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (mp[-input[i]] > 0)
        {
            int k = 0;
            if (input[i] == 0)
                k = mp[input[i]];
            else
                k = mp[input[i]] * mp[-input[i]];
            for (int j = 0; j < k; j++)
                cout << min(input[i], -input[i]) << " " << max(input[i], -input[i]) << endl;
            mp[input[i]] = 0;
            mp[-input[i]] = 0;
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
    pairSum(input1, n);
    return 0;
}
