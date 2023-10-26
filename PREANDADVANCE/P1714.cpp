#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
const int inf = INT_MAX;
int n, m, a[maxn], s[maxn], ans;
deque<int> dq;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    } 
    ans = -inf;
    dq.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (dq.front() + m < i) dq.pop_front();
        ans = max(ans, s[i] - s[dq.front()]);
        while (!dq.empty() && s[dq.back()] >= s[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout << ans;
    return 0;
}