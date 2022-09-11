#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

int dis[10001];
vector<pair<int, int>> edge[10001];
void dijestra(int start)
{
	priority_queue<pair<int, int>> q;
	q.push({ 0,start });
	while (!q.empty())
	{
		int current = q.top().second;
		int distance = -q.top().first;
		q.pop();
		for (int i = 0; i < edge[current].size();i++)
		{
			int next = edge[current][i].second;
			int nextdistance = edge[current][i].first + distance;
			if (dis[next] > nextdistance)
			{
				dis[next] = nextdistance;
				q.push({ -nextdistance,next });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for (int i = 0; i <= 10000; i++)
	{
		edge[i].push_back({ 1,i + 1 });
	}
	int N, D;
	cin >> N >> D;
	for (int i = 0; i < N; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		edge[x].push_back({ d,y });
	}
	fill(&dis[0], &dis[10001], INF);
	dijestra(0);
	cout << dis[D];
}