#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+5;
struct Cow
{
    int x, h;
    bool operator < (const Cow A) const 
    {
        return x < A.x;
    }
};
Cow cows[maxn];
int n, d, ans, le[maxn], ri[maxn];
deque<Cow> q1, q2;
int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> cows[i].x >> cows[i].h;
    sort(cows + 1, cows + n + 1);
    for (int i = 1; i <= n; i++)
    {
        while (!q1.empty() && cows[i].x - q1.front().x > d) q1.pop_front();
        if (!q1.empty()) le[i] = q1.front().h;
        else le[i] = 0;
        while (!q1.empty() && cows[i].h > q1.back().h) q1.pop_back();
        q1.push_back(cows[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        while (!q2.empty() && q2.front().x - cows[i].x > d) q2.pop_front();
        if (!q2.empty()) ri[i] = q2.front().h;
        else ri[i] = 0;
        while (!q2.empty() && cows[i].h > q2.back().h) q2.pop_back();
        q2.push_back(cows[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (le[i] >= cows[i].h * 2 && ri[i] >= cows[i].h * 2) ans ++;
    }
    cout << ans << endl;
    return 0;
}