#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

const int INF = INT_MAX; // 无限远

// n 为点数，m 为边数
// edges 为一个二元组的数组，表示边的起点、终点和权值
// values 为一个长度为 n 的数组，表示每个点的权值
// start 为起点，end 为终点
pair<int, int> longest_path(int n, int m, vector<pair<pair<int, int>, int>> edges, vector<int> values, int start, int end)
{
    // 初始化距离数组
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    // 定义一个堆，用来维护每个结点的距离
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push(make_pair(start, 0));
    // 定义一个数组，用来记录每个结点是否被经过
    vector<bool> visited(n + 1, false);

    // 定义一个变量，用来记录经过的不同点的权值之和
    int sum = 0;

    while (!heap.empty())
    {
        // 取出堆顶元素
        pair<int, int> curr = heap.top();
        heap.pop();

        // 如果当前结点没有被经过，则计算它的权值之和
        if (!visited[curr.first])
        {
            visited[curr.first] = true;
            sum += values[curr.first];
        }

        // 遍历与当前结点相连的边
        for (int i = 0; i < m; i++)
        {
            int u = edges[i].first.first;
            int v = edges[i].first.second;
            int w = edges[i].second;
            if (u == curr.first)
            {
                // 如果经过当前结点可以更新 v 结点的距离
                if (dist[u] + w < dist[v])
                {
                    // 更新 v 结点的距离
                    dist[v] = dist[u] + w;
                    // 插入 v 结点到堆中
                    heap.push(make_pair(v, dist[v]));
                }
            }
        }
    }
    return make_pair(sum, sum);
}

int main()
{
    int n, m;
    cin >> n >> m;
    // 输入每个结点的权值
    vector<int> values(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> values[i];

    // 输入每条边的起点、终点和权
    vector<pair<pair<int, int>, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(make_pair(u, v), 1));
    }
    // 输入起点和终点
    int start, end;
    cin >> start >> end;

    // 求解最长路问题
    pair<int, int> result = longest_path(n, m, edges, values, start, end);

    // 输出经过的不同点的权值之和
    cout << result.second << endl;

    return 0;

}