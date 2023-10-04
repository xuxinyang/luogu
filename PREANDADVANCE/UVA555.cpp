#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
struct Card
{
    char h, d;
};
map<char, int> mp1 = {
    {'C', 1},
    {'D', 2},
    {'S', 3},
    {'H', 4}};
map<char, int> mp2 = {
    {'2', 1}, {'3', 2}, {'4', 3}, {'5', 4}, {'6', 5}, {'7', 6}, {'8', 7}, {'9', 8}, {'T', 9}, {'J', 10}, {'Q', 11}, {'K', 12}, {'A', 13}};
map<char, int> mp3 = {
    {'S', 0}, {'W', 1}, {'N', 2}, {'E', 3}
};
map<int, char> mp4 = {
    {0, 'S'}, {1, 'W'}, {2, 'N'}, {3, 'E'}
};
bool cmp(Card x, Card y)
{
    if (mp1[x.h] == mp1[y.h])
        return mp2[x.d] < mp2[y.d];
    else
        return mp1[x.h] < mp1[y.h];
}
Card cards[5][15];
char c, type, num;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> c && c != '#')
    {
        int p = mp3[c];
        memset(cards, 0, sizeof(cards));
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> cards[(j+1+p)%4][i].h >> cards[(j+1+p)%4][i].d;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            sort(cards[i], cards[i] + 13, cmp);
        }
        for (int i = 0; i < 4; i++)
        {
            cout << mp4[i] << ": ";
            for (int j = 0; j < 12; j++)
            {
                cout << cards[i][j].h << cards[i][j].d << " ";
            }
            cout << cards[i][12].h << cards[i][12].d;
            cout << "\n";
        }
    }
    return 0;
}
// c: a1 a2 a3 a4 a5 a6 a7 a8 a9 10 11 12 13
// S: C3 C5 C7 CT CJ D9 DT DJ S3 SK H2 H9 HT