#include <bits/stdc++.h>
using namespace std;
map<char, char> mp1, mp2;
string s1, s2, s;
int main()
{
    cin >> s1 >> s2 >> s;
    for (int i = 0; i < s1.length(); i++)
    {
        if ((mp1.count(s1[i]) && mp1[s1[i]] != s2[i]) || (mp2.count(s2[i]) && mp2[s2[i]] != s1[i]))
        {
            cout << "Failed" << endl;
            return 0;
        }
        else
        {
            mp1[s1[i]] = s2[i];
            mp2[s2[i]] = s1[i];
        }
    }
    if (mp2.size() != 26)
    {
        cout << "Failed" << endl;
            return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        cout << mp1[s[i]];
    }
    return 0;
}