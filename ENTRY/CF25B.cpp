#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    cin >> n;
    cin >> s;
    if (n == 2 || n == 3) cout << s;
    else
    {
        if (n % 2 == 1)
        {
            for (int i = 0; i < n - 3; i += 2)
            {
                cout << s[i] << s[i+1] << "-";
            }
            cout << s[n-3] << s[n-2] << s[n-1];
        }
        else
        {
            for (int i = 0; i < n - 2; i += 2)
            {
                cout << s[i] << s[i+1] << "-";
            }
            cout << s[n-2] << s[n-1];
        }
    }

    return 0;
}