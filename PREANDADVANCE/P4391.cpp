#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e6+5;
int n, kmp[maxn];
char ss[maxn];
int main()
{
    cin >> n;
    cin >> (ss + 1);
    int j = 0;
    for (int i = 2; i <= n; ++i)
    {
        while (j && ss[i] != ss[j + 1])
            j = kmp[j];
        if (ss[i] == ss[j + 1])
            ++j;
        kmp[i] = j;
    }
    printf("%d", n - kmp[n]);
    return 0;
}