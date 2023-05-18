#include <iostream>
using namespace std;
int n, c[100][100];
int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << 0 << "\n"
             << 0;
        return 0;
    }
    cout << n * (n - 3) * (n * n + 6 * n - 31) / 48 << "\n";
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= i + (n + 1) / 2; ++j)
            c[i][(j - 1) % n + 1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << c[i][j] << " ";
        cout << "\n";
    }
    return 0;
}