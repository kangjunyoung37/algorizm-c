#include<iostream>
using namespace std;

int map[201][201];
int result[201][201];
int n, m;
void floyd()
{
	for (int m = 1; m <=n; m++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (map[i][j] > map[i][m] + map[j][m])
				{
					if (result[i][m] != 0)
					{
						result[i][j] = result[i][m];
					}
					else
					{
						result[i][j] = m;
					}
				
					map[i][j] = map[i][m] + map[j][m];
				
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = 987654321;
			result[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x][y] = d;
		map[y][x] = d;
		result[x][y] = y;
		result[y][x] = x;
	}
	floyd();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				cout << "-" << " ";
				continue;
			}
				
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

}