#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+5;
int m[maxn];
int l, r, L, R, k;
int main()
{
    cin >> l >> r >> L >> R >> k;
    for (int i = l; i <= r; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 1; k < i; k++)
            {
                if (j != k)
                {
                    int v1 = 0;
                    int v2 = 0;
                    while (v1 <= R)
                    {
                        if (v2 % 2 == 0)
                        {
                            v1 = v1 * i + j;
                        }
                        else
                        {
                            v1 = v1 * i + k;
                        }
                        v2++;
                        if (v1 >= L && v1 <= R)
                        {
                            m[v1]++;
                        }
                    }
                }
            }
        }
    }
    for (int i = L; i <= R; i++)
    {
        if (m[i] == k)
        {
            cout << i << endl;
        }
    }
    return 0;
}