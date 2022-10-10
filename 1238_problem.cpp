#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
vector<pair<int, int>> edge[1001];
int dis[1001];
int result[1001];

void dijestra(int start)
{
	dis[start] = 0;
	priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({ 0,start });
	while (!q.empty())
	{
		int current = q.top().second;
		int distance = q.top().first;
		q.pop();
		for (int i = 0; i < edge[current].size(); i++)
		{
			int next = edge[current][i].first;
			int nextdis = distance + edge[current][i].second;
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
	fill(&dis[0], &dis[1001], INF);
	int N, M, X;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		edge[x].push_back({ y,d });
		
	}
	int answer = 0;
	dijestra(X);
	for (int i = 1; i <= N; i++)
	{
		result[i] = dis[i];
	}
	for (int i = 1; i <= N; i++)
	{
		fill(&dis[0], &dis[1001], INF);
		dijestra(i);
		result[i] += dis[X];
	}
	
	for (int i = 1; i <= N; i++)
	{
		if (answer < result[i])
		{
			answer = result[i];
		}
	}

	cout << answer;
}