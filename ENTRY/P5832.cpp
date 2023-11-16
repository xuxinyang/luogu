#include <bits/stdc++.h>
using namespace std;
int n, s, m;
char a[250];
void c(int i, int j)
{
    if (a[i] == a[j])
    {
        s++;
        c(i + 1, j + 1);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int w = 1; w <= n; w++)
    {
        for (int b = w + 1; b <= n; b++)
        {
            s = 0;
            c(w, b);
            if (s > m) m = s; 
        }
    }
    printf("%d", m + 1);
    return 0;
}