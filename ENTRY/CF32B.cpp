#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.') cout << 0;
        if (s[i] == '-')
        {
            if (s[i+1] == '.') cout << 1;
            if (s[i+1] == '-') cout << 2;
            s[i+1] = '*';
        }
    }
    return 0;
}