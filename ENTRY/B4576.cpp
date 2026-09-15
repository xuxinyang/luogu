#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (i*16+j+1 == a) cout << char(a);
            else if (i*16+j+1 == b) cout << char(b);
            else if (i*16+j+1 == c) cout << char(c);
            else cout << '*';
        }
        cout << "\n";
    }
    return 0;
}