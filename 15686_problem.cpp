#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int map[51][51];
int result[14];
int  N, K ,ans = 987654321;

void func(int x, int start)
{
	if (x == K)
	{
		int sum = 0;
		//for (int i = 0; i < K; i++)
		//{
		//	cout << result[i] << " ";
		//}
		//cout << "\n";
		for (int i = 0;i < house.size();i++)
		{
			int A = 987654321;
			int hx = house[i].first;
			int hy = house[i].second;
			for (int j = 0; j < K; j++)
			{
				if (A > abs(hx - chicken[result[j]].first) + abs(hy - chicken[result[j]].second))
				{
					A = abs(hx - chicken[result[j]].first) + abs(hy - chicken[result[j]].second);
				}
			}
			sum += A;
		}
		if (ans > sum)
		{
			ans = sum;
		}
		return;
	}

	for (int i = start; i < chicken.size(); i++)
	{
		result[x] = i;
		func(x + 1, i + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				house.push_back({ i,j });
			}
			if (map[i][j] == 2)
			{
				chicken.push_back({ i,j });
			}
		}
	}
	func(0, 0);
	cout << ans;
	
}