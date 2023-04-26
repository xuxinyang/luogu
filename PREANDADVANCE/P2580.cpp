#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> ump;
int n, m;
string s1, s2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1;
        ump[s1] = 1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> s2;
        if (ump.find(s2) == ump.end())
        {
            cout << "WRONG\n";
        }
        else if (ump[s2] == 1)
        {
            cout << "OK\n";
            ump[s2]++;
        }
        else cout << "REPEAT\n";
    } 
    return 0;
}