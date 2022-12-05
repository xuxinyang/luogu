#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int n, t, f[maxn], x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        t = max(x, t);
        int m = sqrt(x);
        for (int i = 1; i <= m; i++)
            if (x % i == 0)
            {
                f[i]++;
                if (x != i * i) f[x/i]++; 
            } 
    }
    x = t;
    for (int i = 1; i <= n; i++)
    {
        while (f[x] < i) x--;
        cout << x << "\n";
    }
    return 0;
}