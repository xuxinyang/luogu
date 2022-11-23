#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int n, a[N], b[N], ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    } 
    for (int i = 1; i <= n; i++)
    {
        int p = i;
        while (a[i] < a[i+1] && i + 1 <= n) b[p]++, i++;
    }
    // cout << 1 << endl;
    cout << *max_element(b + 1, b + n + 1) + 1 << endl;
    return 0;
}