#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e6 + 5;
const int maxm = 1.5e5+5;
int n, ans, f[maxn], maxx;
struct Cow
{
    int x, y, cnt;
};
Cow cows[maxm];
bool cmp(Cow A, Cow B)
{
    if (A.x == B.x) return A.y < B.y;
    else return A.x < B.x;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cows[i].x >> cows[i].y;
        cows[i].cnt = cows[i].y - cows[i].x + 1;
        maxx = max(maxx, cows[i].y);
    }
    sort(cows + 1, cows + n + 1, cmp);
    int j = 0;
    for (int i = 0; i <= maxx; i++)
    {
        f[i] = max(i-1 < 0 ? f[i]:f[i-1], f[i]);
        while (cows[j].x == i && j <= n)
        {
            f[cows[j].y] = max(f[cows[j].y], f[cows[j].x-1] + cows[j].cnt);
            j++;
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}