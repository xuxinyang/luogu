#include <bits/stdc++.h>
using namespace std;
#define re register
int n, m;
char f, last = ' ';
int main()
{
    cin >> n >> m;
    for (re int i = 1; i <= n; i++)
    {
        f = getchar();
        while (f < '0' || f > '9') f = getchar();
        for (re int j = 2; j <= m; j++)
        {
            char t = getchar();
            if (t != f)
            {
                cout << "NO";
                return 0;
            }
        }
        if (last == f)
        {
            cout << "NO";
            return 0;
        }
        last = f;
    }
    cout << "YES";
    return 0;
}