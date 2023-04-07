#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int n, k, sum[maxn], f[maxn], cnt = 1;
struct Task
{
    int begin, time;
};
bool cmp(Task x, Task y)
{
    return x.begin > y.begin;
}
Task tasks[maxn];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> tasks[i].begin >> tasks[i].time;
        sum[tasks[i].begin]++;
    }
    sort(tasks + 1, tasks + k + 1, cmp);
    for (int i = n; i >= 1; i--)
    {
        if (sum[i] == 0) f[i] = f[i+1] + 1;
        else
        {
            for (int j = 1; j <= sum[i]; j++)
            {
                f[i] = max(f[i], f[i+tasks[cnt].time]);
                cnt++;
            }
        }
    }
    cout << f[1] << endl;
    return 0;
}