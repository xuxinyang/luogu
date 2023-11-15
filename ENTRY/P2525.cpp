#include <bits/stdc++.h>
using namespace std;
int n, m, f[15], a[15];
char c[15];
vector<int> v;
int cantor()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (c[i] > c[j]) s++;
        }
        res += s * f[n-i-1];
    }
    return res;
}
void incantor(int k)
{
    v.clear();
    // while (!v.empty()) v.erase(v.end());
    for (int i = 1; i <= n; i++) v.push_back(i);
    for (int i = 1; i < n; i++)
    {
        a[i] = v[k / f[n-i]];
        v.erase(v.begin() + k / f[n-i]);
        k %= f[n-i];
    }
    a[n] = v[0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    f[0] = 1;
    for (int i = 1; i <= 10; i++) f[i] = f[i-1] * i;
    incantor(cantor()-1);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}