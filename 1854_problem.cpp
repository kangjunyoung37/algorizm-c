#include<iostream>
#include<queue>
#define MAX_E 987654321
using namespace std;

vector<pair<int, int>> map[1001];

int n, m, k;
priority_queue<int> dat[1001];
void dijestra()
{
	priority_queue<pair<int, int>> q;
	q.push({ 0, 1 });
	dat[1].push(0);
	while (!q.empty())
	{
		int cur = q.top().second;
		int dis = -q.top().first;
		q.pop();
		for (int i = 0; i < map[cur].size();i++)
		{
			int next = map[cur][i].second;
			int nextdis = dis + map[cur][i].first;

			if (dat[next].size() < k)
			{
				dat[next].push(nextdis);
				q.push({ -nextdis,next });
			}
			else
			{
				if (dat[next].top() > nextdis)
				{
					dat[next].pop();
					dat[next].push(nextdis);
					q.push({ -nextdis,next });
				}
			}
		}
	}


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 0;i < m; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x].push_back({ d,y });
	}
	dijestra();

	for (int i = 1; i <= n; i++)
	{
		if (dat[i].size() < k)
		{
			cout << "-1" << "\n";
		}
		else
		{
			cout << dat[i].top() << "\n";
		}
	}

}