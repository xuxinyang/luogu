#include <bits/stdc++.h>
using namespace std;
int n;
char c[105];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    cin >> c;
    int ind, diff;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == '1')
        {
            ind = i; break;
        }
    }
    for (int i = ind + 1; i < n; i++)
    {
        if (c[i] == '1')
        {
            diff = i - ind;
            ind = i;
            break;
        }
    }
    int k = ind;
    for (int i = ind + 1; i < n; i++)
    {
        if (c[i] == '1')
        {
            if (i - k != diff)
            {
                cout << "NO";
                return 0;
            }
            else
            {
                k = i;
            }
        }
    }
    cout << "YES" << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}