#include <bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    int s = 9*(int)pow(10, n-1);
    int t = s % k;
    for (int i = 1; i <= k; i++)
    {
        if (t != 0 && (t > i || i == k)) cout << s/k + 1 << " ";
        else cout << s/k << " ";
    }
    return 0;
}