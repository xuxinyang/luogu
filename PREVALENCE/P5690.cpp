#include <bits/stdc++.h>
using namespace std;
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int a, b, cnt=0;
    scanf("%d-%d", &a, &b);
    if (a == 0) cnt++, a = 1;
    if (a > 12)
    {
        cnt++;
        if (a/10==1) a = 12;
        else
        {
            if (a%10 == 2) a = 12;
            else if (a%10 == 0) a = 10;
            else a = a%10;
        }
    }
    if (b > months[a]) cnt++;
    cout << cnt;
    return 0;
}