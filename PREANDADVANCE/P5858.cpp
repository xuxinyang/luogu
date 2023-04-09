#include <bits/stdc++.h>
using namespace std;
#define ll long long
int s, w, n;
ll f[5005][5005], a[5005], ans = LLONG_MIN;
deque<int> dq;
int main()
{
    cin >> n >> w >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= w; j++)
            f[i][j] = LLONG_MIN;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (dq.size()) dq.pop_back();
        for (int j = 1; j <= min(w, s-1); j++)
        {
            while (dq.size() && f[i-1][j] >= f[i-1][dq.back()]) dq.pop_back();
            dq.push_back(j);
        } 
        for (int j = 1; j <= min(i, w); j++)
        {
            if (f[i-1][j-1] != LLONG_MIN)
                f[i][j] = f[i-1][j-1] + a[i] * j;
            while (dq.size() && dq.front() < j) dq.pop_front();
            if (j + s - 1 <= w)
            {
                while (dq.size() && f[i-1][j+s-1] >= f[i-1][dq.back()]) dq.pop_back();
                dq.push_back(j+s-1);
            }
            if (f[i-1][dq.front()] != LLONG_MIN)
                f[i][j] = max(f[i][j], f[i-1][dq.front()] + a[i]*j);
        }
    }
    for (int i = 1; i <= w; i++) ans = max(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}