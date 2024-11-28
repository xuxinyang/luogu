#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int n, m, a[maxn], ans, cur;
unordered_map<int, int> ump;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int i = 1, j = 1;
    ump[a[i]] = 1;
    ans = INT_MAX;
    while (j < n)
    {
        // 移动右指针
        while (ump.size() < m && j < n)
        {
            j++;
            if (ump.count(a[j]) == 0) ump[a[j]] = 1;
            else ump[a[j]]++;
        }
        // 移动左指针缩小
        while (ump.size() == m && i < j)
        {
            ump[a[i]]--;
            if (ump[a[i]] == 0)
            {
                ump.erase(a[i]);
                cur = (j-i+1)*10;
                i++;
                break;
            }
            i++;
        }    
        ans = min(ans, cur);
    }
    cout << ans;
    return 0;
}