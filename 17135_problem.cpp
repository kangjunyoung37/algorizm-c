#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int map[16][16], N, M, D, temp[16][16], check[16][16], ans = 0;
int dx[3] = { 0,-1,0 };
int dy[3] = { -1,0,1 };
void simul(int x,int y, int z)
{
	int visit[16][16];
	int pos[3] = { x,y,z };
	int kill = 0;
	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < M; j++)
		{
			temp[i][j] = map[i][j];
			check[i][j] = 0;
		}
	}
	int P = N;
	queue<pair<int, int>> q;
	while (P > 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					visit[j][k] = 0;
				}
			}
			q = queue<pair<int, int>>();
			int rx = P - 1;
			int ry = pos[i];
			q.push({ rx,ry });
			visit[rx][ry] = 1;
			while (!q.empty())
			{
				int curX = q.front().first;
				int curY = q.front().second;			
				q.pop();
				if (temp[curX][curY] == 1)
				{
					check[curX][curY] = 1;
					break;
				}
				for (int a = 0; a < 3; a++)
				{
					int nextX = curX + dx[a];
					int nextY = curY + dy[a];
					if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)
						continue;
					if (abs(nextX - P) + abs(nextY - pos[i]) <= D)
					{
						if (visit[nextX][nextY] == 0)
						{
							q.push({ nextX,nextY });
							visit[nextX][nextY] = 1;
						}
					}
				}
			}

		}
		for (int i = 0; i < N;i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (check[i][j] == 1)
				{
					temp[i][j] = 0;
				}
			}
		}
		P--;
	}
	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (check[i][j] == 1)
			{
				kill++;
			}
		}
	}

	ans = max(kill, ans);
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0;j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = i + 1; j < M; j++)
		{
			for (int k = j + 1; k < M; k++)
			{
				simul(i, j, k);
			}
		}
	}
	cout << ans;

}