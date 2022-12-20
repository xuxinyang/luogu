#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n, a, b;
ull calc(int n, int r)
{
    ull ans = 1;
    for (int i = 1; i <= r; ++i)
    {
        ans *= n - i + 1;
        ans /= i;
    }
    return ans;
}
int main()
{
    cin >> n >> a >> b;
    ull ans = calc(a+n, n) * calc(b+n, n);
    if (ans == 2) ans = 1;
    cout << ans << endl;
    return 0;
}