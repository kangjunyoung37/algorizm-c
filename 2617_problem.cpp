#include<iostream>
#define MAX_E 987654321
using namespace std;
int N, M;

int map[101][101];
int cnt = 0;
void floyd()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
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
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
			{
				map[i][j] = 0;
				continue;
			}
			map[i][j] = MAX_E;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		//map[y][x] = 1;
	}
	floyd();
	for (int i = 1;i <= N; i++)
	{
		bool check = false;
		int sum = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i != j && map[j][i] != MAX_E)
			{
				sum += 1;
			}
		
			
		}
		if (sum >= ((N + 1) / 2))
		{
			check = true;
		}
		sum = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i != j && map[i][j] != MAX_E)
			{
				sum += 1;
			}
		}
		if (sum > N - ((N + 1) / 2))
		{
			check = true;
		}
		if (check) cnt += 1;
		

	}
	cout << cnt;
}