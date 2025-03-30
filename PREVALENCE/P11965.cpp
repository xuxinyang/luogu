#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll n, ans;
string s;
map<int, int> mp;
int main()
{
    cin >> n;
    cin >> s;
    int  v = 0;
    mp[v]++;
    for (int i = 0; i < n; i++)
    {
        v ^= (1 << (s[i] - '0'));
        ans += mp[v];
        mp[v]++;
    }
    cout << ans << endl;
    return 0;
}