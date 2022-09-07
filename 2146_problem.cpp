#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int map[101][101];
int visit[101][101];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int N;
vector<pair<int, int>> zero;

int bfs(int x, int y)
{
	int dist[101][101] = {0,};
	queue<pair<int, int>> q;
	int mindist = 987654321;
	dist[x][y] = 0;
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
			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= N)
			{
				continue;
			}
			if (dist[cdx][cdy] != 0)
				continue;
			if (map[x][y] == map[cdx][cdy])
				continue;
			if (map[cdx][cdy] != 0 && map[cdx][cdy] != map[cx][cy])
			{
				mindist = min(mindist, dist[cx][cy]);
				continue;
			}
			q.push({ cdx,cdy });
			dist[cdx][cdy] = dist[cx][cy] + 1;

		}
	}
	return mindist;
	
}
int main()
{


	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			visit[i][j] = -1;
		}
	}
	queue<pair<int, int>> q;
	int Num = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == -1 && map[i][j] == 1)
			{
				q.push({ i,j });
				map[i][j] = Num;
				while (!q.empty())
				{
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++)
					{
						int cdx = cx + dx[i];
						int cdy = cy + dy[i];
						if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= N)
						{
							continue;
						}
						if (map[cdx][cdy] == 1 && visit[cdx][cdy] == -1)
						{
							map[cdx][cdy] = Num;
							q.push({ cdx,cdy });
							visit[cdx][cdy] = 0;
						}
						if (map[cdx][cdy] == 0 && visit[cdx][cdy] == -1)
						{
							zero.push_back({ cx,cy });
							visit[cdx][cdy] = 0;
						}
					}
				}
				Num++;
			}
		}
	}
	int ans = 987654321;
	for (int i = 0; i < zero.size(); i++)
	{
		ans = min(ans, bfs(zero[i].first, zero[i].second));
	}
	cout << ans;


}