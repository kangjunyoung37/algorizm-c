#include<iostream>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visit[1000][1000][2];
int N, M;
string map[1000];
queue<tuple<int, int, int>> q;
int bfs()
{
	visit[0][0][0] = 1;
	q.push({ 0,0,0 });
	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int v = get<2>(q.front());
		if (x == N - 1 && y == M - 1)
		{
			return visit[x][y][v];
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cdx = x + dx[i];
			int cdy = y + dy[i];
			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= M)
			{
				continue;
			}
			if (map[cdx][cdy] == '1' && v == 0)
			{
				visit[cdx][cdy][1] = visit[x][y][0] + 1;
				q.push({ cdx,cdy,1 });
			}
			else if (map[cdx][cdy] == '0' && visit[cdx][cdy][v] == 0)
			{
				q.push({ cdx,cdy,v });
				visit[cdx][cdy][v] = visit[x][y][v] + 1;
			}
		}
		
	}
	return -1;
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}
	int answer = bfs();
	cout << answer;


}