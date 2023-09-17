#include <bits/stdc++.h>
using namespace std;
int s, t, w;
string jam;
int main()
{
    cin >> s >> t >> w;
    cin >> jam;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = w-1; j > 0; j--)
        {
            if (jam[j]-'a'+1 <= j-w+t)
            {
                jam[j]++;
                for (int k = j+1; k < w; k++) jam[k] = jam[k-1]+1;
                cout << jam << endl;
                break;
            }
        }
    }
    return 0;
}