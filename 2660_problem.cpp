#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int map[51][51];
int score[51];
void floyed()
{
	for (int m = 1; m <= N; m++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (map[i][j] > map[i][m] + map[m][j])
				{
					map[i][j] = map[i][m] + map[m][j];
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
			{
				continue;
			}
			map[i][j] = 1000;
		}
	}
	int x, y;
	while (1) {

		cin >> x >> y;
		if (x == -1 && y == -1)
		{
			break;
		}
		map[x][y] = 1;
		map[y][x] = 1;

	}
	floyed();
	int temp = 1000;
	int max = 0;
	vector<int> v;
	for (int i = 1; i <= N; i++)
	{
		max = 0;
		for (int j = 1; j <= N; j++)
		{
			if (max < map[i][j])
			{
				max = map[i][j];
			}
		}
		if (temp > max)
		{
			temp = max;
			v.clear();
			v.push_back(i);
		}
		else if (temp == max)
		{
			v.push_back(i);
		}

	}
	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= N; j++)
	//	{
	//		cout << map[i][j];
	//	}
	//	cout << "\n";
	//}
	cout << temp <<" " << v.size() << "\n";

	for (int i = 0; i < v.size();i++)
	{
		cout << v[i] << " ";
	}

}