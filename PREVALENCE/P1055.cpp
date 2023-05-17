#include <bits/stdc++.h>
using namespace std;
string s;
int ans, p;
int main()
{
    cin >> s;
    for (int i = 0; i < s.length()-2; i++)
    {
        if (s[i] == '-') continue;
        ans += (s[i]-'0') * (++p);
    }
    ans %= 11;
    if (ans == 10 && s[s.length()-1] == 'X'
    || ans == s[s.length()-1]-'0')
    {
        cout << "Right";
    }
    else
    {
        cout << s.substr(0, s.length()-1);
        if (ans == 10) cout << "X";
        else cout << ans;
    }
    return 0;
}