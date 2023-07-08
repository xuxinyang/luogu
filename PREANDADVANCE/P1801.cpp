#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int a[maxn], u[maxn], m, n, s, k = 1;
priority_queue<int, vector<int>, greater<int> > pqs;
priority_queue<int, vector<int>, less<int> > pqb;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> u[i];
    for (int i = 1; i <= m; i++)
    {
        pqb.push(a[i]);
        if (pqb.size() > s)
        {
            pqs.push(pqb.top());
            pqb.pop();
        }
        while (u[k] == i)
        {
            s++;
            cout << pqs.top() << "\n";
            pqb.push(pqs.top());
            pqs.pop();
            k++;
        }
    }
    return 0;
}