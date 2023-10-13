#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin >> s;
    cout << "solution-";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            cout << char(s[i]+32);
        else if (s[i] == '_')
            cout << "-";
        else cout << s[i];
    }
    return 0;
}