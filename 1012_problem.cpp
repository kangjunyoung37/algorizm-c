#include<iostream>
#include<algorithm>
#include<queue>
#define MAX_S 52
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };



int main() {
	
	int num;
	
	cin >> num;
	for (int cs = 0; cs < num; cs++)
	{
		int cnt = 0;
		bool visit[MAX_S][MAX_S] = {false,};
		int map[MAX_S][MAX_S] = { 0, };
		int M, N, kimchi;
		cin >> M >> N >> kimchi;

		for (int i = 0;i < M; i++)
			for (int j = 0;j < N;j++)
			{
				map[i][j] = 0;
				visit[i][j] = false;
			}
		for (int i = 0; i < kimchi; i++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 1 && visit[i][j] == false)
				{
					queue<pair<int, int>> q;
					visit[i][j] = true;
					q.push(make_pair(i, j));
					while (!q.empty())
					{
						int cx = q.front().first;
						int cy = q.front().second;
						q.pop();
						for (int a = 0; a < 4; a++)
						{
							int cdx = cx + dx[a];
							int cdy = cy + dy[a];
							if (cdx < 0 || cdx >= M || cdy < 0 || cdy >= N) continue;
							if (map[cdx][cdy] == 0 || visit[cdx][cdy]) continue;

							visit[cdx][cdy] = true;
							q.push(make_pair(cdx, cdy));

						}
					

					}
					cnt++;
				}
			}
		}
		cout << cnt << "\n";

		


	}
}