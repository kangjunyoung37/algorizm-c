#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1001
#define MAX_E 10001
#define INF 987654321
using namespace std;

int dis[MAX] = { INF };
vector<pair<int, int>> map[MAX_E + 1];
void dij(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dis[start] = 0;
	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		for (int i = 0; i < map[current].size(); i++)
		{
			int Next = map[current][i].second;
			int Nextdis = distance+map[current][i].first;
			if (dis[Next] > Nextdis)
			{
				dis[Next] = Nextdis;
				pq.push(make_pair(-Nextdis, Next));
			}

		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M, X;
	cin >> N >> M >> X;
	int max_result = 0;
	for (int i = 0; i < M; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		map[a].push_back(make_pair(d,b));
	}
	for (int i = 1; i <= N; i++)
	{
		fill(&dis[0], &dis[N + 1], INF);
		dij(i);
		int temp1 = dis[X];
		fill(&dis[0], &dis[N + 1], INF);
		dij(X);
		int temp2 = dis[i];

		if (max_result < temp1 + temp2)
		{
			max_result = temp1 + temp2;
		}

	}


	cout << max_result;
	
}