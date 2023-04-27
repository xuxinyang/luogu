#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
char c;
int p;
string s[maxn], ans[maxn];
vector<string> vs;
vector<int> vt;
int main()
{
    while ((cin >> c) && c != EOF)
    {
        if (c >= 'A' && c <= 'Z') s[++p] = c;
        else s[p] += c;
    }
    vs.push_back(s[0]), vt.push_back(1);
    for (int i = 1; i <= p; i++)
    {
        if (s[i] > vs.back())
        {
            vs.push_back(s[i]);
            vt.push_back(vs.size());
        }
        else
        {
            int pos = lower_bound(vs.begin(), vs.end(), s[i]) - vs.begin();
            vs[pos] = s[i];
            vt.push_back(pos + 1);
        }
    }
    int m = vs.size(), cnt = 0;
    for (int i = p; m > 0; i--)
        if (vt[i] == m) ans[++cnt] = s[i], m--;
    for (int i = cnt; i >= 1; i--) cout << ans[i];
    return 0;
}