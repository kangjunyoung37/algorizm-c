#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
string map[101];
int dp[101][101];
int N, M;
queue<pair<int, int>> q;
void dijestra()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dp[i][j] = 10e9;
		}
	}

	dp[0][0] = 0;
	q.push(make_pair(0, 0));

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
			if (map[cdx][cdy] == '0')
			{
				
				if (dp[cdx][cdy] > dp[x][y])
				{
					dp[cdx][cdy] = dp[x][y];
					q.push(make_pair(cdx, cdy));
				}
				
			}
			else
			{
				if (dp[cdx][cdy] > dp[x][y] + 1)
				{
					dp[cdx][cdy] = dp[x][y] + 1;
					q.push(make_pair(cdx, cdy));
				}
				
			}

		}
		

	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	dijestra();
	cout << dp[N - 1][M - 1];

}