#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[20001];
int dis[20001];
void dijestra(int s)
{
	fill(&dis[0], &dis[20001], INF);
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,s });
	while (!q.empty())
	{
		int cur = q.top().second;
		int distance = q.top().first;
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextdis = graph[cur][i].second + distance;
			if (dis[next] > nextdis)
			{
				q.push({ nextdis,next });
				dis[next] = nextdis;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int V, E;
	cin >> V >> E;
	int Start;
	cin >> Start;
	for (int i = 0; i < E; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		graph[x].push_back({ y,d });
	}
	dijestra(Start);
	for (int i = 1; i <= V; i++)
	{
		if (dis[i] == INF)
		{
			cout << "INF" << "\n";
			continue;
		}
		cout << dis[i] << "\n";
	}

}