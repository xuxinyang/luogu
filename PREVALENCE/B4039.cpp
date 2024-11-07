#include <bits/stdc++.h>
using namespace std;
bool check(string s)
{
    int len = s.length();
    for (int i = 0; i < len/2; i++)
    {
        if (s[i] != s[len-1-i]) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        bool flag = 0;
        cin >> s;
        int l = s.length();
        for (int j = 1; j < l-2; j++)
        {
            if (check(s.substr(0, j+1)) && check(s.substr(j+1, l-j-1)))
            {
                flag = 1;
                cout << "Yes\n";
                break;
            }
        }
        if (!flag) cout << "No\n";
    }
    return 0;
}