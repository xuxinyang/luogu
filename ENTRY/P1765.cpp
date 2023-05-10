#include <bits/stdc++.h>
using namespace std;
char c[205];
const int alpha[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
int ans;

int main()
{
    cin.getline(c, 205);
    int len = strlen(c);
    for (int i = 0; i < len; i++)
    {
        if (c[i] == ' ') ans += 1;
        else ans += alpha[c[i] - 'a'];
    }
    cout << ans << endl;
    return 0;
}