// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int t = 1;
    for (int i = 0; i < s.length(); i++)
    {
        int cnt = 0;
        if (s[i] == ' ')
        {
            while (s[i] == ' ')
            {
                cnt++;
                i++;
            }
        }
        while (cnt >= t)
        {
            cnt -= t;
            cout << "\n";
            t += 1;
        }
        for (int j = 1; j <= cnt; j++) cout << ' ';
        cout << s[i];
    }
    return 0;
}