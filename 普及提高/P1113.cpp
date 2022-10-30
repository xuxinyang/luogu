#include <bits/stdc++.h>
using namespace std;
int n, idx, len, need, ans[10005], maxx;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> idx >> len;
        int tmp = 0;
        while (cin >> need && need)
        {
            tmp = max(ans[need], tmp);
        }
        ans[idx] = tmp + len;
        maxx = max(ans[idx], maxx);
    }
    cout << maxx << endl;
    return 0;
}