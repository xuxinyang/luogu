#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, cnt=0;
    set<int> s1, s2;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s1.insert(x);
    } 
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        s2.insert(x);
    } 
    for (auto x : s1)
    {
        if (s2.count(x)) cnt++;
    }
    cout << cnt;
    return 0;
}