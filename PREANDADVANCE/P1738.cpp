#include <bits/stdc++.h>
using namespace std;
int n;
string s, dir;
set<string> se;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        dir = "";
        for (auto k : s)
        {
            if (k == '/') se.insert(dir);
            dir += k;
        }
        se.insert(dir);
        cout << se.size() - 1 << "\n";
    }
    return 0;
}