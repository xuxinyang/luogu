#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
string s[maxn], t[maxn], s1;
long long n, m, cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (getline(cin, s1) && s1 != "EOF")
    {
        n++;
        for (char c : s1)
            if (c == '<')
            { 
                if (!s[n].empty()) s[n].pop_back();
            }
            else s[n].push_back(c);
    }
    while (getline(cin, s1) && s1 != "EOF")
    {
        if (++m > n) break;
        for (char c: s1)
            if (c == '<')
            {
                if (!t[m].empty()) t[m].pop_back();
            }
            else t[m].push_back(c);
        for (int i = 0; i < (int)min(t[m].size(), s[m].size()); i++)
            cnt += (s[m][i] == t[m][i]);
        
    }
    cin >> m;
    cout << (long long)(cnt * 60.0/m + 0.5);
    return 0;
}