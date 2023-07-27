#include <bits/stdc++.h>
using namespace std;
int m, s, t, s1, s2;
int main()
{
    int cur_t = 0;
    cin >> m >> s >> t;
    for (int i = 1; i <= t; i++)
    {
        s1 += 17;
        if (m >= 10) s2 += 60, m -= 10;
        else m += 4;
        if (s2 > s1) s1 = s2;
        if (s1 > s)
        {
            cout << "Yes\n" << i << "\n";
            return 0; 
        }
    }
    cout << "No\n" << s1 << "\n";
    return 0;
}