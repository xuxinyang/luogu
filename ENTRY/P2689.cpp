#include <bits/stdc++.h>
using namespace std;
int sx, sy, tx, ty, t, ans;
char d; 
int main()
{
    cin >> sx >> sy;
    cin >> tx >> ty;
    cin >> t;
    while (t--)
    {
        cin >> d;
        switch (d)
        {
            case 'N':
                if (sy < ty) sy++, ans++;
                break;
            case 'S':
                if (sy > ty) sy--, ans++;
                break;
            case 'E':
                if (sx < tx) sx++, ans++;
                break;
            case 'W':
                if (sx > tx) sx--, ans++;
            default:
                break;
        }
    }
    if (sx == tx && sy == ty) cout << ans;
    else cout << -1;
    return 0;
}