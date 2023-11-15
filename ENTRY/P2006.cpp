#include <bits/stdc++.h>
using namespace std;
const int maxm = 3e4+5;
long long k, m, n, a, b; 
bool flag;
int main()
{
    cin >> k >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if (a == 0 || k/a*b >= n)
        {
            cout << i << " ";
            flag = 1;
        }
    }
    if (!flag) cout << -1;
    return 0;
}