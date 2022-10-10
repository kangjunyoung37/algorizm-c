#include<iostream>
#include<vector>
using namespace std;

int N;
int deep_node; 
long long dis = 0;
vector<pair<int, int>> map[100001];
void dfs(int cur,int prev,long long cost)
{
	if (dis < cost)
	{
		dis = cost;
		deep_node = cur;
	}
	for (int i = 0; i < map[cur].size();i++)
	{
		if (map[cur][i].first == prev)
		{
			continue;
		}
		dfs(map[cur][i].first, cur, cost + map[cur][i].second);

	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		while (1)
		{
			int x, d;
			cin >> x;
			if (x == -1)
			{
				break;
			}
			cin >> d;
			map[a].push_back({ x, d });

		}

	}
	dfs(1, 0, 0);
	dis = 0;
	dfs(deep_node, 0, 0);
	cout << dis ;
}