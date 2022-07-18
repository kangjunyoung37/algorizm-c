#include<iostream>
#include<queue>
using namespace std;

int dx[8] = { 1,-1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,1,-1,-1,1,-1,1 };
int map[51][51];
bool visit[51][51];
int w, h;
void bfs(int x, int y)
{
	visit[x][y] = true;
	map[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int cdx = cx + dx[i];
			int cdy = cy + dy[i];
			if (cdx < 0 || cdy < 0 || cdx >= h || cdy >= w)
				continue;
			if (map[cdx][cdy] == 1 && !visit[cdx][cdy])
			{
				visit[cdx][cdy] = true;
				map[cdx][cdy] = 0;
				q.push(make_pair(cdx, cdy));
			}
		}

	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	while (1)
	{
		cin >> w >> h;

		int cnt = 0;
		if (w == 0 && h == 0)
		{
			break;
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
				visit[i][j] = false;
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				
				if (!visit[i][j] && map[i][j] == 1)
				{
					bfs(i, j);
					cnt += 1;
				}
			}
		}
		cout << cnt << "\n";


	}
	

}