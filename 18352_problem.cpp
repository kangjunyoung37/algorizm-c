#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int dis[300001];
vector<pair<int, int>> graph[300001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	bool isgo = false;
	for (int i = 0;i < M; i++)
	{
		int a, b;
		cin >> a >>  b;
		graph[a].push_back(make_pair(1, b));
		

	}
	fill(&dis[0], &dis[N + 1], 987654321);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, X));
	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[current].size();i++)
		{
			int nextdistane = distance + graph[current][i].first;
			int next = graph[current][i].second;
			if (dis[next] > nextdistane)
			{
				dis[next] = nextdistane;
				pq.push(make_pair(-nextdistane, next));
			}
		}
	}
	dis[X] = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dis[i] == K)
		{
			isgo = true;
			cout << i << " ";
		}

	}
	if (isgo == false)
	{
		cout << -1; 
		return 0;
	}
}