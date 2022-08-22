#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


vector<pair<int, int>> map[100001];
bool bfs(int start,int end, int limit)
{
	int visited[100001] = { false, };
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == end)
		{
			return true;
		}
		for (int i = 0; i < map[cur].size(); i++)
		{
			int next = map[cur][i].first;
			int weight = map[cur][i].second;

			if (!visited[next] && weight >= limit)
			{
				q.push(next);
				visited[next] = true;
			}
		}



	}
	return false;

}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N, M,Start,End,ans = 0, mx = 0;
	cin >> N >> M >> Start >> End;
	for (int i = 0; i < M; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x].push_back({ y,d });
		map[y].push_back({ x,d });
		mx = max(mx, d);
	}

	int left = 1;
	while (left <= mx)
	{
		int mid = (left + mx) / 2;

		if (bfs(Start, End, mid))
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			mx = mid - 1;
		}

	}
	cout << ans;
}