#include<iostream>
#include<vector>

#define MAX_N 1002
using namespace std;
int node, edge;

bool visit[MAX_N];

void dfs(int start , vector<vector<int>> &map)
{
	
	if (visit[start]) return;
	visit[start] = true;
	for (int i = 0; i < map[start].size(); i++)
	{	
		dfs(map[start][i], map);				
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	cin >> node >> edge;
	vector<vector<int>> map(node + 1);
	fill(&visit[0], &visit[node + 1], false);
	for (int i = 0; i < edge; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x].push_back(y);
		map[y].push_back(x);
	}

	for (int i = 1; i <= node; i++)
	{
		if (!visit[i])
		{
			dfs(i, map);
			cnt++;
		}
	}
	cout << cnt;

}