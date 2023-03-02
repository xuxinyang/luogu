#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[4], b[4];
    for (int i = 1; i <= 3; i++)
        cin >> a[i];
    for (int i = 1; i <= 3; i++)
        cin >> b[i];
    for (int i = 1; i <= 3; i++)
    {
        if (a[i] == b[i])
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO"; // 没找到
    return 0;
}