#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;
const int maxn = 5e4+5;
struct Cow
{
    ll w, s;
}cows[maxn];
bool cmp(Cow A, Cow B)
{
    return A.w+A.s < B.w+B.s;
}
ll n, ans, sum;
int main()
{
    cin >> n;
    ans = -inf;
    for (int i = 1; i <= n; i++) cin >> cows[i].w >> cows[i].s;
    sort(cows+1, cows+n+1, cmp);
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, sum-cows[i].s);
        sum += cows[i].w;
    }
    cout << ans;
    return 0;
}