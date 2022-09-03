#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int map[501][501],N,M;
int visit[501][501];
int temp = 1;
vector<int> ans;
bool comp(const int& a, const int& b)
{
	return a > b;
}
void dfs(int x, int y)
{
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int cdx = x + dx[i];
		int cdy = y + dy[i];
		if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= M)
			continue;
		if (visit[cdx][cdy] == 0 && map[cdx][cdy] == 1)
		{
			dfs(cdx, cdy);
			temp += 1;
		}
	}


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1 && visit[i][j] == 0)
			{
				temp = 1;
				dfs(i, j);
				ans.push_back(temp);		
			}
		}
	}
	sort(ans.begin(), ans.end(),comp);
	
	cout << ans.size()<<"\n";
	if (ans.size() == 0)
	{
		cout << 0;
	}
	else
	{
		cout << ans[0];
	}
}