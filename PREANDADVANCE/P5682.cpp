#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
map<int, int, greater<int> > mp;
map<int, int> ::iterator it;
int n, x, a[5];
int main()
{
    int top1, top2, top3;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    if (mp.size() == 1)
    {
        cout << -1;
        return 0;
    }
    // for (it = mp.begin(); it != mp.end(); it++)
    // {
    //     cout << it -> first << " " << it -> second << "\n";
    // }
    it = mp.begin();
    top1 = it -> first, it++;
    top2 = it -> first, it++;
    if (mp.size() <= 2)
    {
        cout << top1 % top2;
        return 0;
    }
    top3 = it -> first;
    cout << max(top3, top1 % top2);
    return 0;
}