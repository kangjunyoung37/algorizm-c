#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int map[101][101];
int res[101], rep[101];
vector<int> edge[101];
int Parent[101];
int FindParent(int son)
{
	if (Parent[son] == son)
	{
		return son;
	}
	return Parent[son] = FindParent(Parent[son]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		Parent[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				map[i][j] = 0;
				continue;
			}
			map[i][j] = 987654321;

		}
		res[i] = 987654321;
		rep[i] = -1;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;

		x = FindParent(x);
		y = FindParent(y);
		if (x != y)
		{
			Parent[y] = x;
		}

	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1;j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (map[i][k] + map[k][j] < map[i][j])
				{
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int a = FindParent(i); int max = -1;
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 987654321)
			{
				continue;
			}
			if (max < map[i][j]) max = map[i][j];
		}
		if (res[a] > max)
		{
			res[a] = max;
			rep[a] = i;
		}

	}

	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (rep[i] != -1) ans.push_back(rep[i]);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size();i++)
	{
		cout << ans[i] << "\n";
	}
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n;j++)
		{
			if (map[i][j] == 987654321)
			{
				cout << 0 << " ";
				continue;
			}
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/
	//for (int i = 1; i <= n; i++)
	//{
	//	cout << Parent[i] << " ";
	//}

}