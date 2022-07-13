#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX_V 805
#define MAX_D 200001
#define INF 1e9
using namespace std;

int N, E;
int dis[MAX_V];
vector<pair<int, int>> map[MAX_D];
void dijstra(int start)
{
	fill(&dis[0], &dis[N+1], INF);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	dis[start] = 0;
	while (!pq.empty())
	{
		int current = pq.top().second;
		int currentdis = pq.top().first;
		pq.pop();
		for (int i = 0; i < map[current].size(); i++)
		{
			int next = map[current][i].second;
			int nextdis = map[current][i].first + currentdis;
			
			if (dis[next] > nextdis)
			{
				dis[next] = nextdis;
				pq.push(make_pair( nextdis, next));
			}

		}

	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x].push_back(make_pair(d, y));
		map[y].push_back(make_pair(d, x));
	}
	int v1, v2;
	cin >> v1 >> v2;
	long long temp1, temp2;
	dijstra(1);
	temp1 = dis[v1];
	temp2 = dis[v2];

	dijstra(v1);
	temp1 += dis[v2];
	dijstra(v2);
	temp1 += dis[N];

	dijstra(v2);
	temp2 += dis[v1];
	dijstra(v1);
	temp2 += dis[N];

	if (temp1 >= INF && temp2 >= INF)
	{
		cout << -1;
	}
	else
	{
		cout << min(temp1, temp2);
	}

	
}