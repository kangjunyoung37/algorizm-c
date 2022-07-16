#include<iostream>

using namespace std;

int N;
int map[101][101];


void floyd()
{
	for(int m = 1 ; m <= N; m++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
			{
				if (i == j)			
					continue;
				
				if (map[i][m] == map[m][j] && map[i][m] != 0)
				{
					map[i][j] = map[i][m];
				}
			}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			map[i][j] = 0;
		}
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = -1;//반대방향

	}
	floyd();

	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				continue;
			if (map[i][j] == 0)
			{
				cnt += 1;

			}

		}
		cout << cnt << "\n";
	
	}

}