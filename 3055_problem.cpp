#include<iostream>
#include<queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
char map[51][51];
int check[51][51];
int N, M;
queue<pair<int, int>> wq;
queue<pair<int, int>> aq;

int bfs()
{
	int size = aq.size();
	while (size--)
	{
		int x = aq.front().first;
		int y = aq.front().second;
		aq.pop();
		
		if (map[x][y] == 'D')
		{
			return check[x][y];
		}
		for (int i = 0; i < 4; i++)
		{
			int cdx = x + dx[i];
			int cdy = y + dy[i];
			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= M)
			{
				continue;
			}
			if (map[cdx][cdy] == '*' || map[cdx][cdy] == 'S' || map[cdx][cdy] == 'X')
			{
				continue;
			}
			aq.push({ cdx,cdy });
			check[cdx][cdy] = check[x][y] + 1;
			if (map[cdx][cdy] != 'D')
			{
				map[cdx][cdy] = 'S';
			}
		}
	}
	return -1;

}
void water_bfs()
{
	queue<pair<int, int>> q;
	int size = wq.size();
	for (int i = 0; i < size; i++)
	{
		q.push(wq.front());
		wq.pop();
	}
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cdx = x + dx[i];
			int cdy = y + dy[i];
			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= M)
			{
				continue;
			}
			if (map[cdx][cdy] == '.')
			{
				map[cdx][cdy] = '*';
				wq.push({ cdx,cdy });
			}
		}
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
			{
				aq.push({ i,j });
			}
			else if (map[i][j] == '*')
			{
				wq.push({ i,j });
			}
			check[i][j] = 0;
		}
	}
	while (1)
	{
		water_bfs();

		int result = bfs();
		if (result != -1)
		{
			cout << result;
			break;
		}
		if (aq.empty())
		{
			cout << "KAKTUS";
			break;
		}
	}
	//water_bfs();
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
}