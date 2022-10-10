#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;
int M, N;
string map;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int temp[1000][1000];
int visit[1000][1000][2];
queue <tuple<int, int, int>> q;

int bfs()
{
	q.push({ 0,0,0 });
	visit[0][0][0] = 1;
	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int v = get<2>(q.front());

		if (x == M - 1 && y == N - 1)
		{
			return visit[x][y][v];
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cdx = x + dx[i];
			int cdy = y + dy[i];
			if (cdx < 0 || cdy < 0 || cdx >= M || cdy >= N)
			{
				continue;
			}
			if (v == 0 && temp[cdx][cdy] == 1)
			{
				q.push({ cdx,cdy,1 });
				visit[cdx][cdy][1] = visit[x][y][0] + 1;
			}
			else if (temp[cdx][cdy] == 0 && visit[cdx][cdy][v] == 0)
			{
				q.push({ cdx,cdy,v });
				visit[cdx][cdy][v] = visit[x][y][v] + 1;
			}

		}
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		cin >> map;
		for (int j = 0; j < map.size();j++)
		{
			temp[i][j] = map[j] - '0';
		}
	}
	int result = bfs();
	cout << result;
}