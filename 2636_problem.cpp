#include<iostream>
#include<queue>
using namespace std;


int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int map[101][101],N,M,cnt = 0,cheeze = 0,ans = 0;
int visit[101][101];

int findcheeze()
{
	cheeze = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M;j++)
		{
			if (map[i][j] == 1)
			{
				cheeze += 1;
			}
			visit[i][j] = 0;
		}
	}
	return cheeze;
}
void bfs(int x, int y)
{
	
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = 1;
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
			{
				continue;
			}
			if (!visit[cdx][cdy])
			{
				if (map[cdx][cdy] == 0)
				{
					q.push({ cdx,cdy });
					visit[cdx][cdy] = 1;
				}
				else
				{
					visit[cdx][cdy] = 1;
					map[cdx][cdy] = 0;
				}
				
			}
	
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
		}
	}
	while (1)
	{
		if (findcheeze() == 0)
		{
			break;
		}
		bfs(0, 0);
		ans = cheeze;
		cnt += 1;
	}
	cout << cnt << "\n"<< ans;
	
}