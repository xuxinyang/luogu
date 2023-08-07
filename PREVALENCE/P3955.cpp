#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, q, k;
string ss[maxn], s;
bool cmp(string x, string y)
{
    if (x.length() == y.length()) return x < y;
    else return x.length() < y.length();
}
bool find(string s, int i, int k)
{
    if (k > ss[i].length()) return false;
    else return ss[i].substr(ss[i].length()-k, k) == s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> ss[i];
    }
    sort(ss + 1, ss + n + 1, cmp);
    for (int i = 1; i <= q; i++)
    {
        bool flag = 0;
        cin >> k >> s;
        for (int j = 1; j <= n; j++)
        {
            if (find(s, j, k))
            {
                cout << ss[j] << "\n";
                flag = 1;
                break;
            }
        }
        if (!flag) cout << "-1\n";
    }
    return 0;
}