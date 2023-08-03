#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
struct Vol
{
    int id, k, t;
};
Vol vols[maxn];
int n;
bool cmp(Vol x, Vol y)
{
    if (x.k * x.t == y.k * y.t)
    {
        if (x.t == y.t) return x.id < y.id;
        else return x.t > y.t;
    }
    else return x.k * x.t > y.k * y.t;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> vols[i].t >> vols[i].k;
        vols[i].id = i;
    }
    sort(vols + 1, vols + n + 1, cmp);
    for (int i = 1; i <= n; i++) cout << vols[i].id << " ";
    return 0;
}