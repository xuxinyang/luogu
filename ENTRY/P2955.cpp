#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        int len = s.length();
        if ((s[len-1] - '0') % 2 == 0) cout << "even\n";
        else cout << "odd\n";
    }
    return 0;
}