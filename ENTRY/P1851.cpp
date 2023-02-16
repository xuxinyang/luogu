#include <bits/stdc++.h>
using namespace std;
// 206
// 1 2 103
int s, a, b;
int main()
{
    cin >> s;
    while (1)
    {
        int sum = 0;
        for (int i = 1; i < s; i++)
            if (s % i == 0) sum += i;
        int k = 0;
        for (int i = 1; i < sum; i++)
        {
            if (sum % i == 0) k += i;
        }
        if (s == k && s != sum)
        {
            cout << s << " " << sum << "\n";
            break;
        }
        s++;
    }
    return 0;
}