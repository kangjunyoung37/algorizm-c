#include<iostream>
using namespace std;
int map[11][11], N ,Start;
int ans = 987654321;
bool visit[11];
void floyd()
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N;j++)
			{
				if (i == j)
					continue;
				if (map[i][j] > map[i][k] + map[k][j])
				{
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
}

void dfs(int index, int planet,int dist)
{
	if (ans < dist)
	{
		return;
	}
	if (planet == N)
	{
		ans = min(dist, ans);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (visit[i]) continue;
		visit[i] = true;
		dfs(i, planet + 1, dist + map[index][i]);
		visit[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> Start;
	for (int i = 0; i < N; i++)
	{
		visit[i] = false;
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	visit[Start] = true;
	floyd();
	dfs(Start, 1, 0);
	cout << ans;
}