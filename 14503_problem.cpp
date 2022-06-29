#include<iostream>

using namespace std;

#define MAX 52
int map[MAX][MAX];
bool visit[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int m, n;
	int x, y;
	int d;
	cin >> m >> n;
	cin >> x >> y >> d;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}

	}

	int cnt = 0;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int checkcount = 0;
	while (true)
	{
		checkcount = 0;
		if (!visit[x][y])
		{
			visit[x][y] = true;
			cnt++;
		}

		for (int i = 0; i < 4; i++)
		{
			checkcount++;
			d = (d + 3) % 4;
			int cdx, cdy;
			cdx = x + dx[d];
			cdy = y + dy[d];
			if (map[cdx][cdy] == 0 && !visit[cdx][cdy])
			{
				x += dx[d];
				y += dy[d];
				checkcount = 0;
				break;
			}

		}

		int back = (d + 2) % 4;

		if (checkcount == 4)
		{
			if (map[x + dx[back]][y + dy[back]] == 1) break;

			x += dx[back];
			y += dy[back];
		}


	}
	cout << cnt;
}