#include <bits/stdc++.h>
using namespace std;
int n;
struct STAGE
{
    int id, h, lx, rx;
};
bool cmp(STAGE x, STAGE y)
{
    if (x.h == y.h) return x.id < y.id;
    else return x.h > y.h;
}
STAGE stages[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        stages[i].id = i;
        cin >> stages[i].h >> stages[i].lx >> stages[i].rx;
    }
    sort(stages + 1, stages + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        int lpos = 0, rpos = 0;
        int k = 0;
        for (int j = 1; j <= n; j++)
        {
            if (stages[j].id == i)
            {
                k = j;
                break;
            }
        }
        // cout << k << " ";
        for (int j = k + 1; j <= n; j++)
        {
            if (stages[j].h < stages[k].h)
            {
                if (stages[j].lx >= stages[k].lx || stages[j].rx <= stages[k].lx) continue;
                if (stages[j].lx < stages[k].lx && stages[j].rx >= stages[k].lx)
                {
                    lpos = stages[j].id;
                    break;
                }
            }

        }
        for (int j = k + 1; j <= n; j++)
        {
            if (stages[j].h < stages[k].h)
            {
                if (stages[j].rx <= stages[k].rx || stages[j].lx >= stages[k].rx) continue;
                if (stages[j].lx <= stages[k].rx && stages[j].rx > stages[k].rx)
                {
                    rpos = stages[j].id;;
                    break;
                }
            }
        }
        cout << lpos << " " << rpos << "\n";
    }

    return 0;
}