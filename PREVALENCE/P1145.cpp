#include <bits/stdc++.h>
using namespace std;
int fid, k, m, beg;
bool check(int mod)
{
    int res = (beg + m - 1) % mod;
    if (res >= k)
    {
        beg = res;
        return 1;
    }
    else return 0;
}
int main()
{
    cin >> k;
    m = k;
    while (!fid)
    {
        fid = 1, beg = 0;
        for (int i = 0; i < k; i++)
        {
            if (!check(2 * k - i))
            {
                fid = 0;
                break;
            }
        }
        m++;
    }
    cout << m - 1 << endl;
    return 0;
}