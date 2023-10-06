#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
int n, a[maxn], f[maxn];
int main()
{
    // 1. 最优子结构，2. 子问题重叠，3. 无后效性
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) f[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
    }
    // 解引用
    cout << *max_element(f+1, f+n+1);
    return 0;
}