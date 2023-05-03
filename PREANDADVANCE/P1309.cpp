#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
struct Play
{
    int score, num;
    bool operator < (const Play X) const
    {
        if (score == X.score) return num < X.num;
        else return score > X.score; 
    }
};
Play players[maxn], wins[maxn>>1], loss[maxn>>1]; 
int w[maxn], n, r, q;
void merge_sort()
{
    int i = 1, j = 1, k = 1;
    while (i <= n && j <= n)
    {
        if (wins[i].score > loss[j].score || wins[i].score == loss[j].score && wins[i].num < loss[j].num)
            players[k++] = wins[i++];
        else 
            players[k++] = loss[j++];
    }
    while (i <= n) players[k++] = wins[i++];
    while (j <= n) players[k++] = loss[j++];
}
int main()
{
    cin >> n >> r >> q;
    for (int i = 1; i <= (n << 1); i++)
    {
        cin >> players[i].score;
        players[i].num = i;
    }
    for (int i = 1; i <= (n << 1); i++) cin >> w[i];
    sort(players + 1, players + 2*n + 1);
    while (r--)
    {
        for (int i = 1; i < (n << 1); i += 2)
        {
            if (w[players[i].num] > w[players[i+1].num])
            {
                wins[(i+1)/2] = players[i];
                wins[(i+1)/2].score += 1;
                loss[(i+1)/2] = players[i+1];
            }
            else
            {
                wins[(i+1)/2] = players[i+1];
                wins[(i+1)/2].score += 1;
                loss[(i+1)/2] = players[i];
            }
        }
        merge_sort();
    }
    cout << players[q].num;
    return 0;
}