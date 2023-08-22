#include <bits/stdc++.h>
using namespace std;
char a, b, c, d;
int sx, sy, ex, ey;
int main()
{
    cin >> a >> b >> c >> d;
    sx = 9 - (b - '0');
    sy = a - 'a' + 1;
    ex = 9 - (d - '0');
    ey = c - 'a' + 1;
    cout << max(abs(sx-ex), abs(sy-ey)) << "\n";
    if (sx >= ex)
    {
        if (sy >= ey)
        {
            int p = sy - ey;
            int q = sx - ex;
            while (p > 0 && q > 0)
            {
                cout << "LU\n";
                p--, q--;
            }
            if (p > 0)
            {
                for (int i = 1; i <= p; i++)
                {
                    cout << "L\n";
                }
            }
            else
            {
                for (int i = 1; i <= q; i++)
                {
                    cout << "U\n";
                }
            }
        }
        else
        {
            int p = ey - sy;
            int q = sx - ex;
            while (p > 0 && q > 0)
            {
                cout << "RU\n";
                p--, q--;
            }
            if (p > 0)
            {
                for (int i = 1; i <= p; i++)
                {
                    cout << "R\n";
                }
            }
            else
            {
                for (int i = 1; i <= q; i++)
                {
                    cout << "U\n";
                }
            }
        }
    }
    else
    {
        if (sy >= ey)
        {
            int p = sy - ey;
            int q = ex - sx;
            while (p > 0 && q > 0)
            {
                cout << "LD\n";
                p--, q--;
            }
            if (p > 0)
            {
                for (int i = 1; i <= p; i++)
                {
                    cout << "L\n";
                }
            }
            else
            {
                for (int i = 1; i <= q; i++)
                {
                    cout << "D\n";
                }
            }
        }
        else
        {
            int p = ey - sy;
            int q = ex - sx;
            while (p > 0 && q > 0)
            {
                cout << "RD\n";
                p--, q--;
            }
            if (p > 0)
            {
                for (int i = 1; i <= p; i++)
                {
                    cout << "R\n";
                }
            }
            else
            {
                for (int i = 1; i <= q; i++)
                {
                    cout << "D\n";
                }
            }
        }
    }
    return 0;
}