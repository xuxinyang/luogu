#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+5;
int a[maxn], n, k, p, flag, score, num[55];
ll ans;
int main()
{
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> score;
        // 判断按钮积分不大于p
        if (score <= p)
        {
            // 找到新的特殊点
            for (int j = i; j > flag; j--) num[a[j]]++;
            flag = i;   // 更新特殊点位
            ans += num[a[i]]-1;
        }
        else ans += num[a[i]];
    }
    cout << ans;
    return 0;
}