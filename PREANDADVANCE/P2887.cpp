#include <bits/stdc++.h>
using namespace std;
const int maxn = 2505;
struct Cow
{
    int l, r;
}cows[maxn];
struct Fs
{
    int d, t;
}fs[maxn];
int C, L, ans;
int main()
{
    cin >> C >> L;
    for (int i = 1; i <= C; i++) cin >> cows[i].l >> cows[i].r;
    for (int i = 1; i <= L; i++) cin >> fs[i].d >> fs[i].t;
    sort(cows+1, cows+C+1, [](Cow A, Cow B){
        return A.r < B.r;
    });
    sort(fs+1, fs+L+1, [](Fs A, Fs B){
        return A.d < B.d;
    });
    for (int i = 1; i <= C; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            if (cows[i].l <= fs[j].d && fs[j].d <= cows[i].r && fs[j].t > 0)
            {
                ans ++;
                fs[j].t--;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}