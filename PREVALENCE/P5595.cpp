#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
string s;
int a[maxn], b[maxn];

bool pd(string s)
{
    bool flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'Z')
            flag = 1;
        if (flag == 1 && s[i] != 'Z')
            return 1;
    }
    return 0;
}

int main()
{
    cin >> s;
    if (pd(s))
        return puts("-1"), 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'X')
            a[i] = 1, b[i] = 0;
        else if (s[i] == 'Y')
            a[i] = 0, b[i] = 1;
        else if (s[i] == 'Z')
            a[i] = 1, b[i] = 1;
    for (int i = 0; i < s.size(); i++)
        cout << a[i];
    cout << endl;
    for (int i = 0; i < s.size(); i++)
        cout << b[i];
    cout << endl;
    return 0;
}