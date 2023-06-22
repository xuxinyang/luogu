#include <bits/stdc++.h>
using namespace std;
int n, a[15];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) a[i] = i;
    do {
        for (int i = 1; i <= n; i++)
        {
            cout << setw(5) << a[i];
        }
        cout << "\n";
    } while (next_permutation(a + 1, a + n + 1));
    return 0;
}