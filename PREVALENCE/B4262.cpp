#include <bits/stdc++.h>
using namespace std;
string s[105];
int n, c[105], p, maxxid;
bool has(string t)
{
    for (int i = 1; i <= p; i++)
    {
        if (s[i] == t)
        {
            c[i]++;
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string t;
        cin >> t;
        for (int j = 0; j < t.size(); j++) t[j] = tolower(t[j]);
        if (!has(t)) s[++p] = t;
    }
    for (int i = 1; i <= p; i++)
    {
        if (c[i] > c[maxxid]) maxxid = i;
    }
    cout << s[maxxid];
    return 0;
}