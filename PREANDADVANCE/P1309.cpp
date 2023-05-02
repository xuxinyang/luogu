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
        if (wins[i].score > loss[j].score || wins[i].score == loss[j].score && wins[i].num < loss[i].num)
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
    sort(players + 1, players + n + 1);
    while (r--)
    {
        int pos = 1;
        for (int i = 1; i < (n << 1); i += 2)
        {
            if (w[players[i].num] > w[players[i+1].num])
            {
                wins[pos].score = players[i].score + 1;
                wins[pos].num = players[i].num;
                loss[pos].score = players[i+1].score;
                loss[pos].num = players[i+1].num;
            }
            else
            {
                wins[pos].score = players[i+1].score + 1;
                wins[pos].num = players[i+1].num;
                loss[pos].score = players[i].score;
                loss[pos].num = players[i].num;
            }
            pos++;
        }
        merge_sort();
    }
    cout << players[q].num;
    return 0;
}