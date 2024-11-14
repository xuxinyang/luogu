#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int inf = 0x3f3f3f3f;
int f[maxn], n, m, k;
vector<int> score[maxn], a, b;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    cin >> m >> n >> k;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        score[a[i]].emplace_back(b[i]);
    }
    vector<int> need(m+5);
    int ans = 0, mx_need = 0, mx_needi = -1;
    for (int i = 1; i <= m; i++)
    {
        sort(score[i].begin(), score[i].end(), cmp);
        int sum = 0;
        for (int j = 0; j < (int)score[i].size(); j++)
        {
            sum += score[i][j];
            if (sum >= k)
            {
                need[i] = j+1;
                break;
            }
        }
        if (sum < k)
        {
            puts("-1");
            return 0;
        }
        ans += need[i];
        if (need[i] > mx_need)
            mx_need = need[i], mx_needi = i;
    }
    if (mx_need - 1 <= ans - mx_need)
    {
        cout << ans << "\n";
        return 0;
    }
    int last = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i != mx_needi) last += score[i].size()-need[i];
    }
    cout << (mx_need-1 <= ans-mx_need + last?2*mx_need-1:-1) << endl;
    return 0;
}