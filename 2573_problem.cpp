#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> map(301, vector<int>(301, 0));
vector<pair<int, int>> ice;
bool visit[301][301];
int N, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int cdx, cdy , cnt = 0;
void dfs(int x,int y)
{
	visit[x][y] = true;
	ice.push_back({ x,y });
	for (int i = 0; i < 4; i++)
	{
		cdx = x + dx[i];
		cdy = y + dy[i];
		if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= M)
		{
			continue;
		}
		if (visit[cdx][cdy] == false && map[cdx][cdy] != 0)
		{
			
			dfs(cdx, cdy);
		}
	}
}
void melt(vector<vector<int>> board)//±‚¡∏ ∏ ¿Ã∂˚ ∫Ò±≥ 
{
	for (int i = 0; i < ice.size(); i++)
	{
		int x = ice[i].first;
		int y = ice[i].second;
		cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			cdx = x + dx[i];
			cdy = y + dy[i];
			if (cdx < 0 || cdy < 0 ||cdx >= N || cdy >= M)
			{
				continue;
			}
			if (board[cdx][cdy] == 0)
			{
				cnt += 1;
			}

		}
		if (board[x][y] - cnt > 0)
		{
			map[x][y] -= cnt;
		}
		else
		{
			map[x][y] = 0;
		}

	}
	ice.clear();

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	int result = 0, group = 0;

	while (1)
	{

		group = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visit[i][j] && map[i][j] != 0)
				{
					dfs(i, j);
					group += 1;
				}
			}
			for (int j = 0; j < M; j++)
			{
				visit[i][j] = false;
			}

		}

		if (group == 0)
		{
			cout << 0;
			return 0;
		}
		if (group >= 2)
		{
			cout << result;
			return 0;
		}
		
		melt(map);
		result += 1;
		
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";

	//}

	}


}