#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[1001];
int dis[1001];

void dijestra(int start)
{
	dis[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,start });
	while (!q.empty())
	{
		int cur = q.top().second;
		int distacne = q.top().first;
		q.pop();
		if (dis[cur] < distacne)
			continue;
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextdis = graph[cur][i].second + distacne;
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
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		graph[x].push_back({ y,d });
	}
	fill(&dis[0], &dis[1001],INF);
	int Start, End;
	cin >> Start >> End;
	dijestra(Start);
	cout << dis[End];
	

}