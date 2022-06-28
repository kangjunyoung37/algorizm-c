#include<iostream>
#include<queue>
using namespace std;
#define MAX 102
string graph[MAX];
int visited[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	queue<pair<int, int>> q;
	int n, m;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> graph[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = -1;
		}
	}
	q.push({ 0,0 });
	visited[0][0] = 0;
	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int cdx = p.first + dx[i];
			int cdy = p.second + dy[i];

			if (cdx < 0 || cdx >= n || cdy < 0 || cdy >= m)
				continue;
			if (visited[cdx][cdy] >= 0 || graph[cdx][cdy] != '1')
				continue;
			visited[cdx][cdy] = visited[p.first][p.second] + 1;
			q.push({ cdx,cdy });

		}
	}
	cout << visited[n - 1][m - 1] + 1;

	


	return 0;
}