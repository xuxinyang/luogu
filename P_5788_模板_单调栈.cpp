#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int num;
    int id;
};
Node node[3000006];
stack <Node> st;
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].num;
        node[i].id = i;
    }
    st.push(node[1]);
    for (int i = 2; i <= n; i++)
    {
        if (node[i].num < st.top().num)
        {
            cout << node[i].id << " ";
            st.pop();
        }
        while (!st.empty() && node[i].num <= st.top().num)
        {
            st.push(node[i]);
            i++;
        }
    }
    cout << 0 << endl;
    return 0;
}