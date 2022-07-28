#include<iostream>
#include<queue>
using namespace std;

int dx[8] = {1,2,1,2,-1,-2,-1,-2};
int dy[8] = {2,1,-2,-1,-2,-1,2,1};
int map[301][301];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int N;
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		int a;
		cin >> a;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				map[i][j] = 0;
				
			}
		}
		int x, y;
		cin >> x >> y;
		int targetx, targety;
		cin >> targetx >> targety;

		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		while (!q.empty())
		{
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			for (int k = 0; k < 8; k++)
			{
				int cdx = cx + dx[k];
				int cdy = cy + dy[k];
				
				if (cdx < 0 || cdy < 0 || cdx >= a || cdy >= a)
				{
					continue;
				}
				if (cdx == x && cdy == y)
				{
					continue;
				}
				if (map[cdx][cdy] == 0)
				{
					map[cdx][cdy] = map[cx][cy] + 1;
					q.push(make_pair(cdx, cdy));
				}
			}
		}
		cout << map[targetx][targety] << "\n";
	}
}