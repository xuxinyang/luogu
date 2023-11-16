#include <bits/stdc++.h>
using namespace std;
char a[105];
int b[105];
int main()
{
    cin >> a;
    int k = strlen(a);
    if (k == 1 && a[0] == '0' || a[0] == '-')
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < k; i++)
            b[i] = a[k-i-1] - '0';
        int c = 0;
        for (int i = 0; i < k; i++)
        {
            b[i] = b[i]*2 + c;
            c = b[i] / 10;
            b[i] = b[i] % 10;
        }
        if (c) b[k++] = c;
        int p = 0;
        while (b[p] == 0) b[p++] = 9;
        b[p] -= 1;
        for (int i = k-1; i >= 0; i--)
        {
            cout << b[i];
        }
    }
    return 0;
}