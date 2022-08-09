#include<iostream>
#include<vector>
using namespace std;


int N;
vector<pair<int, int>> map[10001];
int max_cost = 0; int deep_node = 1;
void dfs(int cur,int prev, int cost)
{
	if (cost > max_cost)
	{
		max_cost = cost;
		deep_node = cur;
	}
	for (int i = 0; i < map[cur].size();i++)
	{
		if (map[cur][i].first != prev)
		{
			dfs(map[cur][i].first, cur, cost + map[cur][i].second);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N-1; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x].push_back({ y,d });
		map[y].push_back({ x,d });
	}
	dfs(1, 0, 0);
	max_cost = 0;
	dfs(deep_node, 0, 0);
	cout << max_cost;

}