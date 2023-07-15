#include <iostream>
using namespace std;
int a, b, cnt;
int main()
{
    cin >> a >> b;
    if (a <= 1 && b <= 1)
    {
        cout << 0 << endl;
        return 0;
    }
    while (true)
    {
        if (a <= 2 && b <= 2)
        {
            cnt += 1;
            cout << cnt << endl;
            break;
        }
        int p = max(a, b);
        int q = min(a, b);
        int t;
        if (p % 2 == 0)
        {
            t = p / 2 - 1;
            cnt += t;
            q += t;
            a = 2;
            b = q;
        }
        else
        {
            t = p / 2;
            cnt += t;
            q += t;
            a = p % 2;
            b = q;
        }
    }
    return 0;
}