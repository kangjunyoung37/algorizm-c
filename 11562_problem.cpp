#include<iostream>
using namespace std;
int map[251][251], n, m;

void floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (map[i][j] > map[i][k] + map[k][j])
				{
					map[i][j] = map[i][k] + map[k][j];
				}
				
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				map[i][j] = 0;
				continue;
			}
			map[i][j] = 987654421;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, on;
		cin >> x >> y >> on;
		if (on)
		{
			map[y][x] = 0;
		}
		else
		{
			map[y][x] = 1;
		}
		map[x][y] = 0;
	}
	floyd();
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << map[x][y] << "\n";
	}
}