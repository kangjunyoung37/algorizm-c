#include<iostream>
#include<string>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
string map[100];
bool visit[100][100];
int cnt = 0;
int N;
void dfs(int x, int y,char color)
{
	if (visit[x][y] || map[x][y] != color) return;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int cdx = x + dx[i];
		int cdy = y + dy[i];
		if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= N)
		{
			continue;
		}
			
		if (!visit[cdx][cdy] && map[x][y] == color)
		{
			dfs(cdx,cdy,color);
		}
	}
}
void dfs2(int x, int y, char color)
{
	if (!visit[x][y] || map[x][y] != color) return;
	visit[x][y] = false;
	for (int i = 0; i < 4; i++)
	{
		int cdx = x + dx[i];
		int cdy = y + dy[i];
		if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= N)
		{
			continue;
		}

		if (visit[cdx][cdy] && map[x][y] == color)
		{
			dfs2(cdx, cdy, color);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				dfs(i, j, map[i][j]);
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'G')
			{
				map[i][j] = 'R';
			}
		}
	}
	cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			if (visit[i][j])
			{
				dfs2(i, j, map[i][j]);
				cnt++;
			}
		}
	}
	cout << cnt;
	

}