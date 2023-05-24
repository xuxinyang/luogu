#include <bits/stdc++.h>
using namespace std;
int k, s, m;
int main()
{
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        if (s + i >= k)
        {
            m += (k-s) * i;
            break;
        }
        s += i;
        m += i * i;
    }
    cout << m;
    return 0;
}