#include <bits/stdc++.h>
using namespace std;
const int maxn = 250005;
int n, w, h[maxn], s[maxn], ans, top;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        while (top > 0 && h[s[top]] > h[i]) top--;
        if (h[s[top]] != h[i]) ans++;
        s[++top] = i;
    }
    cout << ans;
    return 0;
}