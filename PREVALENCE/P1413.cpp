#include <bits/stdc++.h>
using namespace std;
vector<int> ve[10];
int n, ans, r, t;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r >> t;
        ve[r].push_back(t);
    }
    for (int i = 1; i <= 6; i++)
    {
        sort(ve[i].begin(), ve[i].end());
        int j = 0;
        while (j < ve[i].size())
        {
            ans++;
            int k = ve[i][j];
            j++;
            while (j < ve[i].size() && ve[i][j] - k < 60)
                j++;
        }
    }
    cout << ans << endl;
    return 0;
}