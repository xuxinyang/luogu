#include <bits/stdc++.h>
using namespace std;
int n;
map<string, int> mp;
int main()
{
    cin >> n;
    string x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        mp[x] = 1;
    }
    cout << 52-mp.size();
    return 0;
}