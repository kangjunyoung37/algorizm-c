#include<iostream>
#include<vector>
#define INF 987654321
using namespace std;
vector<pair<pair<int, int>, int>> graph;
int dis[501];
int num;
int N, M, W;
void velman()
{
	dis[1] = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < graph.size(); j++)
		{
			int from = graph[j].first.first;
			int to = graph[j].first.second;
			int distance = graph[j].second;
			if (dis[to] > dis[from] + distance) 
				dis[to] = dis[from] + distance;
		}
	}
	for (int i = 0; i < graph.size(); i++)
	{
		int from = graph[i].first.first;
		int to = graph[i].first.second;
		int distance = graph[i].second;

		if (dis[to] > dis[from] + distance)
		{
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> num;
	for (int n = 0; n < num; n++)
	{
		graph.clear();
		fill(&dis[0], &dis[501], INF);
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++)
		{
			int x, y, d;
			cin >> x >> y >> d;
			graph.push_back({{x,y},d });
			graph.push_back({{y,x},d });
		}
		for (int i = 0; i < W; i++)
		{
			int x, y, d;
			cin >> x >> y >> d;
			graph.push_back({ {x,y}, -d });
		}
		velman();
	}
}