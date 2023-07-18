#include <bits/stdc++.h>
using namespace std;
int n;
double h, s1, v, l, k;
int main()
{
    cin >> h >> s1 >> v >> l >> k >> n;
    double maxt = sqrt(h / 5);
    double mint = sqrt((h - k) / 5);
    int s = int(s1 - mint * v + l), e = int(s1 - maxt * v);
    s = min(s, n);
    e = max(e, 0);
    cout << s - e;
}