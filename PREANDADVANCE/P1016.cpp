#include <bits/stdc++.h>
using namespace std;
struct OIL
{
    double cost, x;
    OIL(double c, double n):cost(c), x(n) {}
};
double d1, c, d2, p, D[10], P[10], ans, oi;
int n;
deque<OIL> dq;
int main()
{
    cin >> d1 >> c >> d2 >> p >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> D[i] >> P[i];
        if (D[i]-D[i-1] > c * d2)
        {
            cout << "No Solution\n";
            return 0;
        }
    }
    D[n+1] = d1;
    dq.push_back(OIL(p, oi=c));
    ans += p * c;
    for (int i = 1; i <= n + 1; i++)
    {
        double nd = (D[i]-D[i-1]) / d2;
        while (!dq.empty() && nd > 0)
        {
            OIL front = dq.front();
            dq.pop_front();
            if (front.x > nd)
            {
                oi -= nd;
                dq.push_front(OIL(front.cost, front.x - nd));
                break;
            }
            oi -= front.x;
            nd -= front.x;
        }
        if (i == n + 1)
        {
            while (!dq.empty())
            {
                ans -= dq.front().cost * dq.front().x;
                dq.pop_front();
            }
            break;
        }
        while (!dq.empty() && dq.back().cost > P[i])
        {
            ans -= dq.back().cost * dq.back().x;
            oi -= dq.back().x;
            dq.pop_back();
        }
        ans += (c - oi) * P[i];
        dq.push_back(OIL(P[i], c - oi));
        oi = c;
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}