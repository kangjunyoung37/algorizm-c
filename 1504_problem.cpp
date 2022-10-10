#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321
using namespace std;
vector<pair<int, int>> graph[801];
long long dis[801];

void dijestra(int start)
{
	fill(&dis[0], &dis[801], INF);
	dis[start] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,start });
	while (!q.empty())
	{
		int current = q.top().second;
		long long distance = q.top().first;
		q.pop();
		for (int i = 0; i < graph[current].size(); i++)
		{
			int next = graph[current][i].first;
			long long nextdis = graph[current][i].second + distance;
			if (dis[next] > nextdis)
			{
				dis[next] = nextdis;
				q.push({ nextdis,next });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		graph[x].push_back({ y,d });
		graph[y].push_back({ x,d });
	}
	int node1, node2;
	cin >> node1 >> node2;
	dijestra(1);
	long long temp1;
	long long temp2;
	temp1 = dis[node1];
	temp2 = dis[node2];
	dijestra(node1);
	temp1 += dis[node2];
	dijestra(node2);
	temp1 += dis[N];

	dijestra(node2);
	temp2 += dis[node1];
	dijestra(node1);
	temp2 += dis[N];
	if (temp1 >= INF && temp2 >= INF)
	{
		cout << -1;
	}
	else
	{
		long long answer = min(temp1, temp2);
		cout << answer;
	}

}