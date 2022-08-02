#include<iostream>
using namespace std;
int M, N;
int map[501][501];
int visit[501][501];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int cnt = 0;
int dfs(int x, int y)
{
	if (x == M - 1 && y == N - 1)
	{
		return 1;
	}
	if (visit[x][y] == -1)
	{
		visit[x][y] = 0;
		for (int i = 0; i < 4; i++)
		{
			int cdx = x + dx[i];
			int cdy = y + dy[i];
			if (cdx >= 0 && cdy >= 0 && cdx < M && cdy < N && map[x][y] > map[cdx][cdy])
			{
				visit[x][y] += dfs(cdx, cdy);
			}
		}
	}
	return visit[x][y];

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			visit[i][j] = -1;
		}
	}

	
	cout << dfs(0, 0);
}