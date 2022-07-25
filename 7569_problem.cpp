#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;
int map[101][101][101];
int dz[6] = { 0,0,0,0,-1,1 };
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
queue<tuple<int, int, int>> q;
int M, N, H;
int result = 0;
void bfs()
{
	while (!q.empty())
	{
		int z = get<0>(q.front());
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		q.pop();
		for (int i = 0;i < 6; i++)
		{
			int cdz = z + dz[i];
			int cdx = x + dx[i];
			int cdy = y + dy[i];

			if (cdz < 0 || cdx < 0 || cdy < 0 || cdz >= H || cdx >= N || cdy >= M)
			{
				continue;
			}
			if (map[cdz][cdx][cdy] == 0)
			{
				map[cdz][cdx][cdy] = map[z][x][y] + 1;
				result = max(result, map[cdz][cdx][cdy]);
				q.push({ cdz,cdx,cdy });

			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int m = 0; m < M; m++)
			{
				cin >> map[i][j][m];
				if (map[i][j][m] == 1)
				{
					q.push({ i,j,m });
				}
			}
		}
	}
	bfs();
	//for (int i = 0; i < H; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		for (int m = 0; m < M; m++)
	//		{
	//			cout << map[i][j][m] << " ";
	//		}
	//		cout << "\n";
	//	}
	//}출력 확인
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int m = 0; m < M; m++)
			{
				if (map[i][j][m] == 0)
				{
					cout << -1;
					return 0;
				}
			}
			
		}
	}
	if (result == 0)
	{
		cout << 0;
	}
	else
	{
		cout << result - 1;
	}

}