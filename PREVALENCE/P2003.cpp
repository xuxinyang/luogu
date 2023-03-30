#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct Board
{
    int y, x1, x2;
};
Board boards[105];
int n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> boards[i].y >> boards[i].x1 >> boards[i].x2;
    }
    for (int i = 1; i <= n; i++)
    {
        int c1 = inf, c2 = inf, f1 = 0, f2 = 0;
        double l = boards[i].x1 + 0.5, r = boards[i].x2 - 0.5;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            int ll = boards[j].x1, rr = boards[j].x2;
            if (l > ll && l < rr && boards[i].y > boards[j].y)
                c1 = min(c1, boards[i].y - boards[j].y), f1 = 1;
            if (r > ll && r < rr && boards[i].y > boards[j].y) 
                c2 = min(c2, boards[i].y - boards[j].y), f2 = 1;
        }
        if (!f1) c1 = min(c1, boards[i].y);
        if (!f2) c2 = min(c2, boards[i].y);
        ans += (c1 + c2);
    }
    cout << ans << endl;
    return 0;
}