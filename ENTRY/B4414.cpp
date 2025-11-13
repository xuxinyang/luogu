#include <bits/stdc++.h>
using namespace std;
int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int n, day = 2;
    cin >> n;
    cout << "MON TUE WED THU FRI SAT SUN\n";
    for (int i = 1; i < n; i++) day += m[i];
    day %= 7;
    for (int i = 1; i <= m[n]+day; i++)
    {
        if (i <= day) printf("    ");
        else printf("%3d ", i-day);
        if (i % 7 == 0) cout << "\n";
    }
    return 0;
}