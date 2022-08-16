#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;


char map[101][101];
int ans[101][101];
int N, M;


int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

vector<pair<int, int>> pos;
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cdx = dx[i] + cx;
			int cdy = dy[i] + cy;
			while (cdx >= 0 && cdx < M && cdy >= 0 && cdy < N && map[cdx][cdy] != '*')
			{
				if (ans[cdx][cdy] == 0)
				{
					ans[cdx][cdy] = ans[cx][cy] + 1;
					q.push({ cdx,cdy });
				}
				cdx += dx[i];
				cdy += dy[i];
			}
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'C')
			{
				pos.push_back({ i,j });
			}
		}
	}
	bfs(pos[0].first, pos[0].second);
	//for (int i = 0; i < M; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (ans[i][j] == 10001)
	//		{
	//			cout << 0 << " ";
	//			continue;
	//		}
	//		cout << ans[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	cout << ans[pos[1].first][pos[1].second] - 1;


}