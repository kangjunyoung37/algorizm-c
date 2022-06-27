#include<iostream>
#include<queue>
#include<vector>
#include <utility>



using namespace std;

#define INF 987654321
#define MAX_V 20001
#define MAX_E 30001

vector<pair<int, int>> graph[MAX_V];

int dis[MAX_V] = { INF };
int visited[MAX_V] = { 0 };

void dijkstra(int start)
{
	priority_queue < pair<int, int>> pq;
	pq.push(make_pair(0,start));
	dis[start] = 0;
	visited[start] = 1;
	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;//거리가 짧은 순으로 들어갈 수 있게 음수화 시켜준다
		pq.pop();
		visited[current] = 1;
		
		for (int i = 0; i < graph[current].size(); i++)
		{
			int Next = graph[current][i].second;
			int Nextdis = distance + graph[current][i].first;

			if (dis[Next] < Nextdis) continue;
			if (visited[Next]) continue;

			dis[Next] = Nextdis;
			pq.push(make_pair(-Nextdis, Next));
		}
	}

}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int node, edge;
	int start;
	
	cin >> node >> edge;
	cin >> start;


	for (int i = 0; i < edge; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		graph[a].push_back(make_pair(d, b));
	}
	fill(&dis[0], &dis[node + 1], INF);
	fill(&visited[0], &visited[node + 1], 0);

	dijkstra(start);

	for (int j = 1; j <= node; j++)
	{
		if (dis[j] == INF)
		{
			cout << "INF" << "\n";
		}
		else

		{
			cout << dis[j] << "\n";
		}
	}
	

}

