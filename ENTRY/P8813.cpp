#include <bits/stdc++.h>
using namespace std;
long long a, b, ans = 1;
int main()
{
    cin >> a >> b;
    if (a == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i <= b; i++)
        {
            ans *= a;
            if (ans > 1e9)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}