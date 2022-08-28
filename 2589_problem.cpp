#include<iostream>
#include<queue>
using namespace std;
char map[51][51];
int visit[51][51];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int N, M, result = -1;
vector<pair<int, int>> pos;

void bfs(int x ,int y)
{
	

	visit[x][y] = 1;
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cdx = cx + dx[i];
			int cdy = cy + dy[i];
			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= M)
				continue;
			if (map[cdx][cdy] == 'L' && visit[cdx][cdy] == 0)
			{
				visit[cdx][cdy] = visit[cx][cy] + 1;
				result = max(visit[cdx][cdy], result);
				q.push({ cdx,cdy });
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = 0;
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			visit[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 0 && map[i][j] == 'L')
			{
				bfs(i, j);
			}
		}
	}
	cout << result - 1;
}