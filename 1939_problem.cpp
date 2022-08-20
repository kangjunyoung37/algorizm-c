#include<iostream>
#include<vector>
#include<queue>
#define INF 10000000000005
using namespace std;


vector<pair<long long, int>> map[10005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x].push_back({ d,y });
		map[y].push_back({ d,x });

	}
	int A, B;
	cin >> A >> B;
	long long left = 0, right = 1000000001;
	while (left+1 < right)
	{
		int mid = (left + right) / 2;
		vector<long long> dist(N + 1, INF);
		bool visited[10005] = { false };
		
		priority_queue<pair<long long, int>> q;

		q.push({ 0,A });
		dist[A] = 0;
		while (!q.empty())
		{
			int cur = q.top().second;
			q.pop();
			if (visited[cur])
				continue;
			visited[cur] = true;
			for (int i = 0; i < map[cur].size(); i++)
			{
				long long weight = map[cur][i].first;
				int next = map[cur][i].second;
				if (!visited[next] && weight >= mid && dist[next] > dist[cur] + weight)
				{
					dist[next] = dist[cur] + weight;
					q.push({ -dist[next],next });
				}
			}
		}
		if (dist[B] != INF) left = mid;
		else right = mid;
	}
	cout << left;



}