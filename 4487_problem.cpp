#include<iostream>
#include<queue>
using namespace std;
int map[126][126];
int dp[126][126];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int result = 0;
int N;

struct Node {

	int d, x, y;
	bool operator<(const Node& n) const
	{
		return n.d > d;
	}
};

void dijestra() {

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = 987654321;
		}
	}
	priority_queue <Node> pq;
	pq.push({0,0});
	dp[0][0] = map[0][0];
	while (!pq.empty())
	{
		int cx = pq.top().x;
		int cy = pq.top().y;
		int cd = -pq.top().d;

		pq.pop();
		if (dp[cx][cy] < cd) continue;
		for (int i = 0; i < 4; i++)
		{
			int cdx = cx + dx[i];
			int cdy = cy + dy[i];
			

			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= N)
			{
				continue;
			}
			int distance = dp[cx][cy] + map[cdx][cdy];
			if (dp[cdx][cdy] <= distance) continue;
			dp[cdx][cdy] = distance;
			pq.push({-distance,cdx,cdy });
		}

	}



}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 1;
	while (1)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}
		dijestra();
		cout << "Problem " << cnt << ":" << " " << dp[N - 1][N - 1] << "\n";
		cnt += 1;
	}

}