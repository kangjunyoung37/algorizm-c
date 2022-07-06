#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int map[22][22];
int visit[22][22];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int shark = 2; // 상어 크기 
int eat = 0; //먹은 횟수
int N; // 맵 크기
int result = 0; // 총 결과
int sharkX, sharkY; // 상어 초기 위치

struct Fish {
	int x;
	int y;
	int value;
};
vector<Fish> fish;

bool comp( Fish& a,   Fish& b)
{

	if (a.value == b.value)
	{
		if (a.x == b.x)
		{
			return a.y < b.y;
		}
		return a.x < b.x;
	}
	return a.value < b.value;
}

int bfs(int x, int y) { //거리 구하기
	fish.clear();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = -1;
		}
	}
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int cdx = x + dx[i];
			int cdy = y + dy[i];

			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= N) continue;

			if (visit[cdx][cdy] > -1 || map[cdx][cdy] > shark) continue;

			if (map[cdx][cdy] > 0 && map[cdx][cdy] < shark)
			{
				
				Fish fishwhere;
				fishwhere.x = cdx;
				fishwhere.y = cdy;
				fishwhere.value = visit[x][y] +1 ;
				fish.push_back(fishwhere);
			}
			q.push(make_pair(cdx, cdy));
			visit[cdx][cdy] = visit[x][y] + 1;
		}
	}
	if (!fish.empty())
	{
		sort(fish.begin(), fish.end(), comp);
		auto a = fish[0];
		result += a.value;
		eat++;
		
		sharkX = a.x;
		sharkY = a.y;
		map[a.x][a.y] = 0;
		if (eat == shark)
		{
			shark++;
			eat = 0;
		}
		return 1;

	}
	else
	{
		return 0;
	}
}
int main()
{
	

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				sharkX = i;
				sharkY = j;
			}
		}
	}
	map[sharkX][sharkY] = 0;
	while (true)
	{
		int a = bfs(sharkX, sharkY);
		if (a == 0)
		{
			break;
		}
	}

	cout << result;

}