#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e3+5;
int n, t;
struct Node{
    int v, s;
};
Node p[N];
bool cmp(Node A, Node B){
    return A.s < B.s;
}
double sum;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].v >> p[i].s;
        p[i].s -= t;
    }
    sort(p+1, p+n+1, cmp);
    int l = 0, r = n+1, f = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i].s < 0) l = i;
        if (p[i].s == 0) sum += p[i].v;
        if (p[i].s > 0 && !f) r = i, f = 1;
    }
    int sl = 0, sr = 0;
    for (int i = 1; i <= l; i++) p[i].s = -p[i].s, sl += p[i].s*p[i].v;
    for (int i = r; i <= n; i++) sr += p[i].s*p[i].v;
    if (sl <= sr)   // 右边减少一部分
    {
        for (int i = 1; i <= l; i++) sum += p[i].v;
        for (int i = r; i <= n; i++)
        {
            if (p[i].s*p[i].v <= sl) sl -= p[i].s*p[i].v, sum += p[i].v;
            else 
            {
                sum += 1.0*sl/p[i].s; 
                break;
            }
        }
    }
    else
    {
        for (int i = r; i <= n; i++) sum += p[i].v;
        for (int i = l; i >= 1; i--)
        {
            if (p[i].s * p[i].v <= sr) sr -= p[i].s*p[i].v, sum += p[i].v;
            else
            {
                sum += 1.0*sr/p[i].s;
                break;
            }
        }
    }
    printf("%.3lf", sum);
    return 0;
}