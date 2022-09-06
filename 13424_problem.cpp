#include<iostream>
#include<vector>
#define INF 98764321
using namespace std;
int N, M;
int map[101][101] ,ans ,result;
vector<int> people;
void floyd()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)
					continue;
				if (map[i][j] > map[i][k] + map[k][j])
				{
					map[i][j] = map[i][k] + map[k][j];
				}
			} 
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int Num;
	cin >> Num;
	for (int n = 0; n < Num;n++)
	{
		people.clear();
		ans = INF;
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)
				{
					map[i][j] = 0;
					continue;
				}
				map[i][j] = INF;
			}
		}
		for (int i = 0; i < M; i++)
		{
			int x, y, d;
			cin >> x >> y >> d;
			map[x][y] = d;
			map[y][x] = d;
		}

		floyd();
		int person;
		cin >> person;
		for (int i = 0; i < person; i++)
		{
			int a;
			cin >> a;
			people.push_back(a);
		}
		for (int i = 1; i <= N; i++)
		{	
			int sum = 0;
			for (int j = 0; j < person;j++)
			{
				sum += map[people[j]][i];
			}
			if (ans > sum)
			{
				ans = sum;
				result = i;
			}
			else if (ans == sum)
			{
				if (result > i)
				{
					result = i;
				}
			}
		}
		cout << result << "\n";
	}
	
}