#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n, k;
char c[maxn];
pair<int, int> a[maxn];
int main()
{
    cin >> n >> k >> (c+1);
    int maxx = 0;
    for (int i = 1; i <= n; i++) 
        maxx = max(maxx, c[i]-'a');
    vector<int> v;
    for (int i = 1; i <= n; i++)
        if (c[i]-'a' == maxx) v.push_back(i);
    int cnt = v.size();
    if (cnt % k != 0)
    {
        int len = cnt / k + 1;
        for (int i = 1; i <= len; i++) putchar((char)(maxx+'a'));
    }
    else
    {
        int len = cnt / k;
        for (int i = 1; i <= len; i++) putchar((char)(maxx+'a'));
        for (int i = n; i > v.back(); i--)
        {
            int now = c[i] - 'a';
            if (now >= a[i+1].first) a[i] = make_pair(now, i);
            else a[i] = a[i+1];
        }
        int x = v.back() + 1;
        while (x <= n) putchar((char)(a[x].first+'a')), x = a[x].second+1;
    }
    return 0;
}