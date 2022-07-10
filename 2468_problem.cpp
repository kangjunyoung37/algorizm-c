#include<iostream>
#include<queue>
#define MAX_V 101

int map[MAX_V][MAX_V];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int max_result = 0;//결과 값
int result = 0;
int N;
bool visit[MAX_V][MAX_V];

using namespace std;

void bfs(int x, int y , int rain)
{
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cdx =  a + dx[i];
			int cdy =  b + dy[i];
			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= N)
			{
				continue;
			}
			if (map[cdx][cdy] > rain && visit[cdx][cdy] == false)
			{
				q.push(make_pair(cdx, cdy));
				visit[cdx][cdy] = true;
			}

		}
		
	}

}
int main()
{
	ios_base::sync_with_stdio(0);

	int m_max = 0, m_min = 101;//맵에서 가장 큰 값과 가장 작은 값 
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (m_max < map[i][j])
			{
				m_max = map[i][j];
			}
			if (m_min > map[i][j])
			{
				m_min = map[i][j];
			}
		}
	}
	for (int rain = m_min; rain <= m_max; rain++)
	{
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] > rain && visit[i][j]== false)
				{
					bfs(i, j, rain);
					result++;
				}
				visit[i][j] = false;
			}
		}
		if (max_result < result)
		{
			max_result = result;
		}
		result = 0;
	}
	cout << max_result;
}