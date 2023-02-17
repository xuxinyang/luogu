#include <bits/stdc++.h>
using namespace std;
string s;
int i, j;
int main()
{
    cin >> s;
    s += '/';
    for (i = 0; i < s.length()-1; i++)
    {
        if (s[i] != '/' || s[i] == '/' && s[i+1] != '/')
        {
            cout << s[i];
            j++;
        }
    }
    if (j == 0) cout << '/';
    return 0;
}