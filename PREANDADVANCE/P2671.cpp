#include <bits/stdc++.h>
using namespace std;
const int mod = 1e4+7;
const int N = 1e5+5;
int n, m, ans;
int a[N], b[N], s1[N][2], s2[N][2];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) 
    {
        cin >> b[i];
        s1[b[i]][i%2]++;    // 记录颜色为b[i],且编号与编号奇偶性相同的格子数目
        s2[b[i]][i%2] = (s2[b[i]][i%2] + a[i]) % mod; // 记录颜色为 b[i],且编号与编号1奇偶性相同的格子上面的数字的和
    }
    for (int i = 1; i <= n; i++)
    {
        int y = b[i];
        ans += i * (s2[y][i%2]+a[i]*(s1[y][i%2]-2) % mod) % mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}