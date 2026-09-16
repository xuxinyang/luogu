#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0 ; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        else if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
        else if (s[i] >= '0' && s[i] <= '9') s[i] = '*';
    }
    cout << s;
    return 0;
}