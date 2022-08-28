#include<iostream>
using namespace std;
int n;
int map[501][501];
int visit[501][501];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int dfs(int x, int y)
{
	if (visit[x][y])
	{
		return visit[x][y];
	}
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{

		int cdx = x + dx[i];
		int cdy = y + dy[i];
		if (cdx < 0 || cdy < 0 || cdx >= n || cdy >= n)
			continue;
		if (map[x][y] > map[cdx][cdy])
		{
			visit[x][y] = max(dfs(cdx, cdy)+1, visit[x][y]);
		}
	}
	
	return visit[x][y];

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] == 0)
			{
				dfs(i, j);
			}
			
		}
	}	
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{	
			//cout << visit[i][j] << " ";
			result = max(result, visit[i][j]);
		}
		//cout << "\n";
		
	}
	cout << result;
}