#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int dx[4] = { 0,-1,0, 1 };
int dy[4] = { 1,0,-1,0 };
int map[8][8];
int visit[8][8];
int temp[8][8];
int M, N;
int answer = 0;
vector<pair<int, int>> viruspos;
void BFS()
{
	queue<pair<int, int>> q;
	for (int i = 0; i < viruspos.size(); i++)
	{
		q.push(viruspos[i]);
	}
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cdx = a + dx[i];
			int cdy = b + dy[i];

			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= M)
				continue;
			if (temp[cdx][cdy] == 0)
			{
				temp[cdx][cdy] = 2;
				q.push(make_pair(cdx, cdy));				
			}

		}
	}
	
}
void copymap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			temp[i][j] = map[i][j];
		}
	}
}

int CountSafe() {
	int SafeCount = 0;
	for(int i = 0; i < N; i ++)
		for (int j = 0; j < M; j++)
		{
			if (temp[i][j] == 0)
			{
				SafeCount++;
			}
		}
	return SafeCount;
}

void wall(int x,int start)
{
	if (x == 3)
	{
		copymap();

		BFS();
		
		answer = max(answer,CountSafe());
		
		return;
		
	}	
	for (int i = start; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				wall(x + 1, i);
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				viruspos.push_back(make_pair(i, j));
			}
		}
	}
	wall(0, 0);
	cout << answer;
}