#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 987654321
#define MAX_V 1002
bool visit[MAX_V]= { false};
int dis[MAX_V] = { INF };
vector<pair<int, int>> graph[MAX_V];
void dij(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0,start));
	visit[start] = true;
	dis[start] = 0;
	while (!pq.empty())
	{
		int cureent = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (dis[cureent] < distance) continue;
		visit[cureent] = true;
		for (int i = 0; i < graph[cureent].size(); i++)
		{
			int Next = graph[cureent][i].second;
			int Nextdis = distance + graph[cureent][i].first;
			
			
			if (dis[Next] > Nextdis && !visit[Next])
			{
				dis[Next] = Nextdis;
				pq.push(make_pair(-Nextdis, Next));

			}

		}

	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int node;
	int bus;
	cin >> node >> bus;
	

	
	for (int i = 0; i < bus; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		graph[a].push_back(make_pair(d, b));
	}
	fill(&visit[0], &visit[node + 1], false);
	fill(&dis[0], &dis[node + 1], INF);
	int start, end;
	cin >> start >> end;
	dij(start);

	cout << dis[end];
	
}