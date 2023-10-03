#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;
int a[maxn] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int A, B, N, f[maxn], k, flag;

int main()
{
    cin >> A >> B >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i+13];
    sort(a + 1, a + N + 13+1);
    for (int i = 1; i <= 13 + N; i ++)
    {
        if (a[i] >= A && a[i] <= B)
        {
            f[i] = 1;
            if (!flag) k = i, flag = 1;
        } 
    }
    for (int i = k+1; i <= N + 13; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] >= a[i]-B && a[j] <= a[i]-A)
            {
                f[i] += f[j];
            }
        }
    }
    // for (int i = 0; i <= N + 13; i++) cout << f[i] << " ";
    cout << f[N+13];
    return 0;
}