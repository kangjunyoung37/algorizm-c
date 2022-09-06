#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

struct Distacne
{
	int x;
	int y;
	int d;
};
vector<pair<int, int>> map[1001];
vector<Distacne> dis;


void dijesta(int start)
{
	dis[start].d = 0;
	priority_queue<pair<int, int>> q;
	q.push({ 0,start });
	while (!q.empty())
	{
		int cur = q.top().second;
		int distance = -q.top().first;
		q.pop();
		for (int i = 0; i < map[cur].size();i++)
		{
			int next = map[cur][i].second;
			int nextdistance = map[cur][i].first + distance;
			if (dis[next].d > nextdistance)
			{
				dis[next].x = cur;
				dis[next].y = next;
				dis[next].d = nextdistance;
				q.push({ -nextdistance,next });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
	{
		dis.push_back({0,0,INF});
	}
	for (int i = 0; i < M; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x].push_back({ d,y });
		map[y].push_back({ d,x });
	}
	dijesta(1);
	vector<pair<int,int>>ans;
	for (int i = 1;i <= N; i++)
	{
		if (dis[i].x != 0 && dis[i].y != 0)
		{
			ans.push_back({ dis[i].x,dis[i].y });
		}
		//cout << dis[i].x << " " << dis[i].y << " " << dis[i].d << "\n";
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size();i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}

}