#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn], x = 0;

/**
 * @brief 
 * 找最小值，如果说第1头牛到第n-1头牛的位置中间里够容纳n头牛，且第n-1头牛到第n头牛之间
 * 能够容纳至少两头牛，那么需要将第1头牛放到第n-1头到n头牛中间，第n头牛放到
 * @return int 
 */
int getmin()
{
    if ((a[n - 1] - a[1] == n - 2 && a[n] - a[n - 1] > 2) || 
    (a[n] - a[2] == n - 2 && a[2] - a[1] > 2))
        return 2;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        while (j < n && a[j + 1] - a[i] <= n-1)
            j++;
        x = max(x, j - i + 1);
    }
    return n - x;
}

int getmax()
{
    return max(a[n - 1] - a[1], a[n] - a[2]) - n + 2;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    cout << getmin() << "\n" << getmax();
    return 0;
}