#include<iostream>
#define MAX_L 52
using namespace std;

int map[MAX_L][MAX_L];
bool visit[MAX_L][MAX_L];
int dx[8] = { 0,1,0,-1,-1, -1, 1, 1 };
int dy[8] = { 1,0,-1,0,-1 ,1 ,1 ,-1 };
int w = -1; 
int h = -1;
int result = 0; 
void dfs(int x, int y)
{
	if (visit[x][y])
		return ;
	visit[x][y] = true;
	for (int i = 0; i < 8; i++)
	{
		int cdx = x + dx[i];
		int cdy = y + dy[i];
		if (cdx < 0 || cdy < 0 || cdx >= h || cdy >= w)
		{
			continue;
		}
		if (map[cdx][cdy] == 1 && !visit[cdx][cdy])
		{
			dfs(cdx, cdy);
			
		}	
		
	}
	
	
	
}
int main() {


	while (true)
	{

		
		cin >> w >> h;
		if (w == 0 && h == 0)
		{
			return 0;
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				visit[i][j] = false;
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 &&!visit[i][j])
				{
					dfs(i, j);
					result++;
				}
			}
		}
		
		cout << result << "\n";
		result = 0;
	}
}