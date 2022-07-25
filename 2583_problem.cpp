#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[101][101];
bool visit[101][101];
int M, N, K;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<int> result;
int cnt = 0;
void dfs(int x ,int y) {
	

	cnt += 1;
	visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int cdx = x + dx[i];
		int cdy = y + dy[i];
		if (cdx < 0 || cdy < 0 || cdx >= M || cdy >= N)
		{
			continue;
		}
		if (!visit[cdx][cdy] && map[cdx][cdy] == 0)
		{
			visit[cdx][cdy] = true;
			dfs(cdx, cdy);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
			{
				map[i][j] = 1;
			}
		}
	}

	//for (int i = 0; i < M; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//} 출력 확인

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j] && map[i][j] == 0)
			{
				dfs(i, j);
				result.push_back(cnt);
				cnt = 0;
			}
		}
		
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size();i++)
	{
		cout << result[i] << " ";
	}

	
}