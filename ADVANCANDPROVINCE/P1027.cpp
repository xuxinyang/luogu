#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const double inf = 1e10;
struct City
{
    int x, y;
    int city;
};
int n, s, t, A, B, T[maxn];
double dis[maxn << 2], ans;
City citys[maxn << 2];
bool mark[maxn << 2];
double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
// 求矩形第四个点的坐标
void get4cor(int x1, int y1, int x2, int y2, int x3, int y3, int i)
{
    int ab = pow(x1 - x2, 2) + pow(y1 - y2, 2);
    int ac = pow(x1 - x3, 2) + pow(y1 - y3, 2);
    int bc = pow(x2 - x3, 2) + pow(y2 - y3, 2);
    int x4, y4;
    if (ab + ac == bc)
        x4 = x2 + x3 - x1, y4 = y2 + y3 - y1;
    if (ac + bc == ab)
        x4 = x1 + x2 - x3, y4 = y1 + y2 - y3;
    if (ab + bc == ac)
        x4 = x1 + x3 - x2, y4 = y1 + y3 - y2;
    citys[i + 3].x = x4, citys[i + 3].y = y4;
}
void init()
{
    memset(citys, 0, sizeof(citys));
    memset(mark, 0, sizeof(mark));
    cin >> s >> t >> A >> B;
    for (int i = 1; i <= 4 * s; i += 4)
    {
        cin >> citys[i].x >> citys[i].y;
        cin >> citys[i + 1].x >> citys[i + 1].y;
        cin >> citys[i + 2].x >> citys[i + 2].y;
        cin >> T[i/4+1];
        citys[i].city = citys[i + 1].city = citys[i + 2].city = citys[i + 3].city = i / 4 + 1;
        get4cor(citys[i].x, citys[i].y, citys[i + 1].x, citys[i + 1].y, citys[i + 2].x, citys[i + 2].y, i);
    }
}
void spfa()
{
    queue<int> q;
    for (int i = 1; i <= 4 * s; i++)
        dis[i] = inf;
    for (int i = A * 4 - 3; i <= A * 4; i++)
    {
        dis[i] = 0;
        q.push(i);
        mark[i] = true;
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        mark[x] = false;
        for (int i = 1; i <= 4 * s; i++)
        {
            if (i == x)
                continue;
            double cost = distance(citys[x].x, citys[x].y, citys[i].x, citys[i].y);
            if (citys[i].city == citys[x].city)
                cost *= T[citys[i].city];
            else
                cost *= t;
            if (dis[x] + cost < dis[i])
            {
                dis[i] = dis[x] + cost;
                if (!mark[i])
                    mark[i] = true, q.push(i);
            }
        }
    }
}
int main()
{
    cin >> n;
    while (n--)
    {
        init();
        spfa();
        ans = dis[B * 4];
        for (int i = B * 4 - 3; i < B * 4; i++)
            ans = min(ans, dis[i]);
        cout << fixed << setprecision(1) << ans;
    }
    return 0;
}
