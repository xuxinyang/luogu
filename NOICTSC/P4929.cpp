#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int maxm = 505;
const int maxo = 5505;
int n, m, x, cnt, row[maxn], ans[maxn], col[maxm];
struct DLX
{
    int row, col;
    int left, right, up, down;
};
DLX dlx[maxo];
// DanceLink init
void init()
{
    for (int i = 0; i <= m; i++)
    {
        dlx[i].left = i - 1;
        dlx[i].right = i + 1;
        dlx[i].up = i;
        dlx[i].down = i;
        col[i] = 0;
    }
    dlx[0].left = m;
    dlx[m].right = 0;
    cnt = m;
}
// Link node val = 1
void link(int r, int c)
{
    // 修改结点所在链
    dlx[++cnt].row = r;
    dlx[cnt].col = c;
    dlx[cnt].up = dlx[c].up;
    dlx[cnt].down = c;
    dlx[dlx[cnt].up].down = cnt;
    dlx[c].up = cnt;
    if (!row[r])
    {
        dlx[cnt].left = cnt;
        dlx[cnt].right = cnt;
        row[r] = cnt;
    }
    else
    {
        dlx[cnt].left = dlx[row[r]].left;
        dlx[cnt].right = row[r];
        dlx[dlx[cnt].left].right = cnt;
        dlx[dlx[cnt].right].left = cnt;
    }
    col[c]++;
}
// 删除列元素所在列链以及其中元素对应行
void remove(int c)
{
    for (int i = dlx[c].down; i != c; i = dlx[i].down)
    {
        for (int j = dlx[i].right; j != i; j = dlx[j].right)
        {
            dlx[dlx[j].down].up = dlx[j].up;
            dlx[dlx[j].up].down = dlx[j].down;
            col[dlx[j].col]--;
        }
    }
    dlx[dlx[c].left].right = dlx[c].right;
    dlx[dlx[c].right].left = dlx[c].left;
}
// 恢复列元素所在列链以及其中元素对应行
void resume(int c)
{
    dlx[dlx[c].left].right = c;
    dlx[dlx[c].right].left = c;
    for (int i = dlx[c].down; i != c; i = dlx[i].down)
    {
        for (int j = dlx[i].right; j != i; j = dlx[j].right)
        {
            dlx[dlx[j].down].up = j;
            dlx[dlx[j].up].down = j;
            col[dlx[j].col]++;
        }
    }
}
// 跳舞搜索
bool dance(int dep)
{
    if (dlx[0].right == 0)  // 有解
    {
        for (int i = 1; i <= dep - 1; i++)
        {
            cout << ans[i] << " ";
        }
        return true;
    }
    int cell = dlx[0].right;
    for (int i = dlx[0].right; i ; i = dlx[i].right)
    {
        if (col[i] < col[cell]) cell = i;
    }
    remove(cell);
    for (int i = dlx[cell].down; i != cell; i = dlx[i].down)
    {
        ans[dep] = dlx[i].row;
        for (int j = dlx[i].right; j != i; j = dlx[j].right)
        {
            remove(dlx[j].col);
        }
        if (dance(dep+1)) return true;
        for (int j = dlx[i].right; j != i; j = dlx[j].right)
        {
            resume(dlx[j].col);
        }
    }
    resume(cell);
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            if (x) link(i, j);
        }
    }
    if (!dance(1)) cout << "No Solution!\n";
    return 0;
}