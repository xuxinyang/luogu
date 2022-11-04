#include <iostream>
using namespace std;

int fa[5005], n, m, p;
// 1.初始化，将每个节点初始化为自己，每个节点都是一个集合 
void init()
{
	for (int i = 1; i <= n; i++) fa[i] = i;
}

// 2.查找，递归查找x的祖先，在回溯的过程中将查找路径上的所有集合元素都修改为祖先的集合号 
int find(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);	// 路径压缩递归查找 
}

// 3.合并，如果两个集合（两个帮派）的老大不一样，我们就需要进行合并
void merge(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) fa[fy] = fx;	
} 


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> n >> m >> p;
	init();
	int a, b;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		merge(a, b);
	} 
	for (int i = 1; i <= p; i++)
	{
		cin >> a >> b;
		if (find(a) != find(b)) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}