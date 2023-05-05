#include <bits/stdc++.h>
using namespace std;
char a[10];
int ans;
int main()
{
    cin.getline(a, 10);
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != ' ') ans++;
    }
    cout << ans;
    return 0;
}