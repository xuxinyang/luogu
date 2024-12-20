#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int t, n, a[maxn];
char res[maxn];
bool check(int l1, int r1, int l2, int r2)
{
    for (int i = 1; i < n; i++)
    {
        if (l1<=r1 && ((l2<=r2&&a[l1]==a[l2])||(l1<r1&&a[l1]==a[r1])))
        {
            if (l1 < r1 && a[l1] == a[r1])
            {
                l1++, r1--;
                res[i] = 'L'; res[2*(n-1)-i+1] = 'L';
            }
            else
            {
                l1++, l2++;
                res[i] = 'L'; res[2*(n-1)-i+1] = 'R';
            }
        }
        else if (l2<=r2&&((l1<=r1&&a[r2]==a[r1])||(l2<r2&&a[l2]==a[r2])))
        {
            if (l2 < r2 && a[l2] == a[r2])
            {
                l2++, r2--;
                res[i] = 'R'; res[2*(n-1)-i+1] = 'R';
            }
            else
            {
                r1--, r2--;
                res[i] = 'R'; res[2*(n-1)-i+1] = 'L';
            }
        }
        else return 0;
    }
    return 1;
}
void solve()
{
    cin >> n;
    int p1 = -1, p2 = -1;
    for (int i = 1; i <= (n<<1); i++) cin >> a[i];
    memset(res, 0, sizeof(res));
    for (int i = 2; i <= (n<<1); i++)
        if (a[1] == a[i])
        {
            p1 = i;
            break;
        }
    for (int i = 1; i < (n<<1); i++)
        if (a[n<<1] == a[i])
        {
            p2 = i;
            break;
        }
    if (check(2, p1-1, p1+1, n<<1)) cout << "L" << res+1 << "L\n";
    else if (check(1, p2-1, p2+1, (n<<1)-1)) cout << "R" << res+1 << "L\n";
    else cout << "-1\n";
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}