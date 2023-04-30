#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
struct Ticket
{
    int price, time, used;
};
Ticket tickets[maxn];
int p, q = 1, n, ans, op, pri, tim;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op >> pri >> tim;
        if (!op)
        {
            ans += pri;
            tickets[++p].time = tim;
            tickets[p].price = pri;
        }
        else
        {
            while (q <= p && tickets[q].time + 45 < tim) ++q;
            bool flag = 0;
            for (int j = q; j <= p; j++)
            {
                if (tickets[j].price >= pri && tickets[j].used == 0)
                {
                    flag = 1;
                    tickets[j].used = 1;
                    break;
                }
            }
            if (!flag) ans += pri;
        }
    }
    cout << ans << endl;
    return 0;
}