#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
#define MAX_E 987654321
using namespace std;
int N, M, K;
int dis[101][10001];
struct edge {

	int d;
	int y;
	int c;

};
vector<edge> edges[101];

void dijestra()
{
	priority_queue<tuple<int,int,int>> q;
	q.push({0,0,1});
	dis[1][0] = 0;
	while (!q.empty())
	{
		int cur = get<2>(q.top());
		int cost = get<1>(q.top());
		int time = -get<0>(q.top());
		q.pop();
		if (dis[cur][cost] < time)
		{
			continue;
		}
		for (int i = 0; i < edges[cur].size(); i++)
		{
			int next = edges[cur][i].y;
			int nexttime = edges[cur][i].d + time;
			int nextcost = edges[cur][i].c + cost;
			if (nextcost > M)
			{			
				continue;
			}
			if (dis[next][nextcost] <= nexttime)
			{
				continue;
			}
			for (int j = nextcost; j <= M; j++)
			{
				if (dis[next][j] > nexttime)
				{
					dis[next][j] = nexttime;
				}
			}
			q.push({ -nexttime,nextcost,next });
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int Num;
	cin >> Num;
	for (int z = 0; z < Num; z++)
	{
		int ans = MAX_E;
		cin >> N >> M >> K;
		for (int i = 1; i <= N; i++)
		{
			edges[i].clear();
			for (int j = 0; j <= 10000; j++)
			{
				dis[i][j] = MAX_E;
			}
		}
		for (int i = 0; i < K; i++)
		{
			int x, y, c, d;
			cin >> x >> y >> c >> d;
			edge edge1;
			edge1.y = y;
			edge1.c = c;
			edge1.d = d;
			edges[x].push_back(edge1);
		}
		dijestra();
		for (int i = 0; i <= M; i++)
		{
			ans = min(dis[N][i], ans);
		}
		if (ans == MAX_E)
		{
			cout << "Poor KCM" << "\n";
		}
		else
		{
			cout << ans << "\n";
		}

	}
}