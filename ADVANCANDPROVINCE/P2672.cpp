#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, s[maxn], f[maxn], g[maxn];
struct Node
{
    int dis, tire;
};
Node v[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i].dis;
    for (int i = 1; i <= n; i++) cin >> v[i].tire;
    sort(v+1, v+n+1, [](Node A, Node B){
        return A.tire > B.tire;
    });
    for (int i = 1; i <= n; i++) s[i] = s[i-1]+v[i].tire;
    for (int i = 1; i <= n; i++) f[i] = max(f[i-1], 2*v[i].dis);
    for (int i = n; i >= 1; i--) g[i] = max(g[i+1], 2*v[i].dis+v[i].tire);
    for (int i = 1; i <= n; i++)
        cout << max(s[i]+f[i], s[i-1]+g[i]) << "\n";
    return 0;
}