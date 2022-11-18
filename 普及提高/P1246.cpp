#include <bits/stdc++.h>
using namespace std;
string s, now;
map<string, int> mp;
int cnt;
void dfs(const int len, int k)
{
    if (k > len)
    {
        mp[now] = ++cnt;
        return;
    }
    for (char i = (k==1 ? 'a' : now[k-2] + 1); i <= 'z'; i++)
        now[k-1] = i, dfs(len, k+1); 
}
int main()
{
    cin >> s;
    for (int i = 1; i <= s.length(); i++)
    {
        now.clear(), now.resize(i), dfs(i, 1);
    }
    cout << mp[s] << endl;
    return 0;
}
