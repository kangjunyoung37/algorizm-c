#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321
using namespace std;
int N, M, Start, End ,dis[501];
vector<pair<int,int>> Edge[501], backEdge[501];
void dijestra(int start , vector<pair<int,int>> Graph[501])
{
	fill(&dis[0], &dis[501], INF);
	priority_queue<pair<int, int>> q;
	q.push({ 0,start });
	dis[start] = 0;
	while (!q.empty())
	{
		int cur = q.top().second;
		int distance = -q.top().first;
		q.pop();
		if (dis[cur] < distance)
		{
			continue;
		}
		for (int i = 0; i < Graph[cur].size();i++)
		{
			int next = Graph[cur][i].second;
			int nextdis = Graph[cur][i].first + distance;
			
			if (dis[next] > nextdis)
			{
				dis[next] = nextdis;
				q.push({ -nextdis, next });
			}
			
		}
	}

}
void dfs(int start,int pre)
{
	if (start == Start)
	{
		return;
	}
	for (int i = 0; i < backEdge[start].size(); i++)
	{
		int next = backEdge[start][i].second;
		int dist = backEdge[start][i].first;
		if (dis[next] + pre + dist == dis[End])
		{
			backEdge[start][i].first = INF;
			dfs(next, pre + dist);
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while (1)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
		{
			break;
		}
		for (int i = 0; i < N; i++)
		{
			Edge[i].clear();
			backEdge[i].clear();
			
		}
		cin >> Start >> End;
		for (int i = 0; i < M; i++)
		{
			int x, y, d;
			cin >> x >> y >> d;
			Edge[x].push_back({ d,y });
			backEdge[y].push_back({ d,x });
		}
		dijestra(Start ,Edge);

		dfs(End, 0);
		dijestra(End, backEdge);
		if (dis[Start] == INF)
		{
			cout << -1 <<"\n";
		}
		else
		{
			cout << dis[Start] << "\n";
		}
	}
}