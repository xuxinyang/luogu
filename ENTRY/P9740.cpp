#include <bits/stdc++.h>
using namespace std;
int n, line, sum;
struct Score
{
    int a, b;
};
Score scores[10];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> scores[i].a >> scores[i].b;
        sum += 100/scores[i].a*scores[i].b;
    }
    cin >> line;
    if (sum >= line)
    {
        cout << "Already Au.";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if ((scores[i].a-scores[i].b)*(100/scores[i].a) + sum >= line)
            {
                cout << int(ceil(1.0*(line-sum)/(100/scores[i].a))) << "\n";
            }
            else
            {
                cout << "NaN\n";
            }
        }
    }
    return 0;
}