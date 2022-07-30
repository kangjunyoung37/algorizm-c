#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int map[51][51];
bool visit[51][51];
int N, L, R;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 1;
int total = 0;
int result = 0;
vector<pair<int, int>> Move;
void visitinit() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = false;
		}
	}
}
void bfs(int x, int y) {

	
	visit[x][y] = true;
	queue<pair<int, int>> q;
	Move.clear();
	q.push(make_pair(x, y));
	Move.push_back(make_pair(x, y));
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cdx = cx + dx[i];
			int cdy = cy + dy[i];
			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= N)
			{
				continue;
			}
			if (L <= abs(map[cx][cy] - map[cdx][cdy]) && R >= abs(map[cx][cy] - map[cdx][cdy]) && !visit[cdx][cdy])
			{
				q.push(make_pair(cdx, cdy));
				Move.push_back(make_pair(cdx, cdy));
				visit[cdx][cdy] = true;
			}
		}
	}
	if (Move.size() != 1)
	{
		cnt += 1;
		total = 0;
		for (int i = 0; i < Move.size();i++)
		{
			total += map[Move[i].first][Move[i].second];
		}
		total = (total / Move.size());
		for (int i = 0; i < Move.size(); i++)
		{
			map[Move[i].first][Move[i].second] = total;
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N;j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}Ãâ·Â
	while (1)
	{
		cnt = 0;
		visitinit();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visit[i][j])
				{
					bfs(i, j);
				}
			}
		}
		if (cnt == 0)
		{
			break;
		}
		result += 1;
	}

	cout << result;

}