#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
ll n, p[N], t[N], len;
struct Coin
{
    ll t, x;
}coins[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> coins[i].x >> coins[i].t;
    sort(coins+1, coins+n+1, [&](Coin A, Coin B){
        if (A.x == B.x) return A.t < B.t;
        else return A.x < B.x;
    });
    for (int i = 1; i <= n; i++) p[i] = coins[i].t - coins[i].x;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] < 0) continue;
        if (p[i] >= t[len]) t[++len] = p[i];
        else
        {
            int pos = upper_bound(t+1, t+len+1, p[i])-t;
            t[pos] = p[i];
        }  
    }
    cout << len;
    return 0;
}