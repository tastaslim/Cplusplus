#include <bits/stdc++.h>
using namespace std;
void printUnique(string str)
{
    unordered_map<char, int> mp;
    string m;
    int k = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (mp[str[i]] == 0)
            m[k++] = str[i];
    }
    cout << m << endl;
}

int main()
{
    string str;
    cin >> str;
    printUnique(str);
    return 0;
}
