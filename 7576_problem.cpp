#include<iostream>
#include<queue>
#include<vector>
#define MAX_S 1002
using namespace std;
int box[MAX_S][MAX_S];
int N, M ,x, y, cdx, cdy;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int result = 0;
queue<pair<int,int>> q;
void bfs()
{

	while (!q.empty())
	{
		
		x = q.front().first;
		y = q.front().second;
		
		q.pop();
		
		
		for (int i = 0; i < 4; i++)
		{
			cdx = x + dx[i];
			cdy = y + dy[i];

			if (cdx < 0 || cdy < 0 || cdx >= M || cdy >= N)
			{
				continue;
			}

			if (box[cdx][cdy] == 0)
			{
				box[cdx][cdy] = box[x][y] + 1;
				q.push(make_pair(cdx, cdy));

			}
		}
	

	}

}
int main()
{

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
			{
				q.push({ i,j });
			}
		}
	}
	bfs();

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (box[i][j] == 0)
			{
				cout<< -1;
				return 0;
			}
			if (result < box[i][j])
			{
				result = box[i][j];
			}
		}
	}

	cout << result - 1;

	 
}