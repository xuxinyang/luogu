#include <bits/stdc++.h>
using namespace std;
long long a, b, n, sum = 0, cnt;
int main()
{
    cin >> a >> b >> n;
    for (cnt = 1; sum <= n; cnt++)
    {
        if (cnt % 7 <= 5 && cnt % 7 >= 1)
            sum += a;
        else
            sum += b;
    }
    cnt--;
    cout << cnt;
    return 0;
}