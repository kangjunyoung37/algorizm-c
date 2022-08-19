#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> map[11][11];
int N, M, K;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };
int tree[11][11];
int wintertree[11][11];
struct dead
{
	int x;
	int y;
	int year;
};
vector<dead> a;
void spring()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sort(map[i][j].begin(), map[i][j].end());
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < map[i][j].size();k++)
			{
				if (map[i][j][k] <= tree[i][j])
				{
					tree[i][j] -= map[i][j][k];
					map[i][j][k] += 1;
				}
				else
				{
					a.push_back({ i,j,map[i][j][k] });
					map[i][j].erase(map[i][j].begin() + k);
					k--;
				}
			}
		}
	}
}
void summer()
{
	for (int i = 0;i < a.size(); i++)
	{
		int x = a[i].x;
		int y = a[i].y;
		tree[x][y] += (a[i].year / 2);
	}
	a.clear();a.resize(0);
}
void fall()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < map[i][j].size(); k++)
			{
				if (map[i][j][k] >= 5 && map[i][j][k] % 5 == 0)
				{
					for (int m = 0; m < 8; m++)
					{
						int cdx = i + dx[m];
						int cdy = j + dy[m];
						if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= N)
						{
							continue;
						}
						map[cdx][cdy].push_back(1);
					}
				}
			}
		}
	}
}
void winter()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0;j < N; j++)
		{
			tree[i][j] += wintertree[i][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tree[i][j] = 5;
			cin >> wintertree[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		int x, y, year;
		cin >> x >> y >> year;
		map[x - 1][y - 1].push_back(year);
	}
	while (K>0)
	{
		K--;
		spring();
		summer();
		fall();
		winter();
	}
	int ans = 0;
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		for (int k = 0; k < map[i][j].size(); k++)
	//		{
	//			cout << i << "¿Í" << j << ":" << " " << map[i][j][k] << " ";
	//		}
	//		cout << "\n";
	//	}
	//}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans += map[i][j].size();
		}
	}
	cout << ans;
}