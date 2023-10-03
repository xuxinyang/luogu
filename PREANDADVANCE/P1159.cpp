#include <bits/stdc++.h>
using namespace std;
string ups[105], downs[105], sames[105], name, ranks;
int n, u, d, s, sa[105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> name >> ranks;
        if (ranks[0] == 'U') ups[++u] = name;
        else if (ranks[0] == 'D') downs[++d] = name;
        else sames[++s] = name, sa[i] = 1;
    }
    int l = 1, o = 1, p = 1;
    for (int i = 1; i <= n; i++)
    {
        if (sa[i]) cout << sames[p++] << "\n";
        else if (l != d+1) cout << downs[l++] << "\n";
        else cout << ups[o++] << "\n";
    }
    return 0;
}