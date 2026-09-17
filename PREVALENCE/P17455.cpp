#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6+5;
int n; 
bool v[N];
void init()
{
    memset(v, 1, sizeof v);
    v[1] = v[0] = 0;
    for (int i = 2; i*i < N; i++)
    {
        if (v[i])
        {
            for (int j = i*2; j < N; j += i) v[j] = 0;
        }
    }
}
int main()
{
    int n, cnt = 0;
    init();
    cin >> n;
    for (int i = 2; i <= n/2; i++)
    {
        if (v[i] && v[n-i]) cnt++;
    }
    cout << cnt;
    return 0;
}