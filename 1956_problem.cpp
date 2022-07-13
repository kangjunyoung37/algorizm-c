#include<iostream>
#define INF 987654321
using namespace std;
int V, E;
int map[401][401];
void floyd()
{
	for(int m = 1; m <= V; m++ )
		for(int i = 1; i <=V; i++)
			for (int j = 1; j <= V; j++)
			{
				if (i == j)
					continue;
				map[i][j] = min(map[i][m] + map[m][j], map[i][j]);
			}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E;

	for(int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
		{
			map[i][j] = INF;
		}
	for (int i = 0; i < E; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x][y] = d;

	}
	int result = INF;
	floyd();
	for(int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
		{
			if (i == j)
			{
				continue;
			}
			result = min(result, map[i][j] + map[j][i]);
		}
	
	if (result == INF)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}

}