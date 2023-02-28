#include <cmath>
#include <cstdio>
#include <climits>
using namespace std;
int n, x[10009], y[10009];
double ans = INT_MAX;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) < ans)
            {
                ans = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            }
        }
    }
    printf("%.4lf", ans);
    return 0;
}