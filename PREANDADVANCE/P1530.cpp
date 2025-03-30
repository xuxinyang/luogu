#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int d, n, k, w, s, len;
string res;
int vis[N];
int main()
{
    cin >> n >> d;
    k = n/d, w = -1;
    do {
        res = char(k%10+'0') + res;
        k /= 10;
    } while (k > 0);
    res += '.';
    n = n % d;
    do {
        if (vis[n] != 0)
        {
            w = vis[n];
            break;
        }
        else vis[n] = res.size();
        n *= 10;
        res += char(n/d + '0');
        n %= d;
    } while (n != 0);
    if (w != -1) res += ')';
    len = res.size();
    for (int i = 0; i < len; i++)
    {
        if (i == w)
        {
            cout << '(';
            i--;
            w = -1;
        }
        else cout << res[i];
        s++;
        if (s % 76 == 0) cout << "\n";
    }
    return 0;
}