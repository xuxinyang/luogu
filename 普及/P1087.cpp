#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void dfs(int l, int r)
{
    int mid = (r + l) >> 1;
    if (l < r)
    {
        dfs(l, mid);
        dfs(mid + 1, r);
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = l; i <= r; i++)
    if (s[i-1] == '0') cnt0++;
    else cnt1++;
    if (cnt0 && cnt1) cout << "F";
    else if (cnt0) cout << "B";
    else cout << "I";
}
int main()
{
    cin >> n >> s;
    dfs(1, 1 << n);
    return 0;
}