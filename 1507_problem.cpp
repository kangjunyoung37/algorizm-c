#include<iostream>
using namespace std;
int N;
int map[21][21];
bool temp[21][21];
bool isgo;
int ans = 0;
void floyd()
{
	for (int m = 0; m < N; m++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i == j || i == m || m == j)
				{
					continue;
				}
				if (map[i][j] > map[i][m] + map[m][j])
				{
					isgo = true;
					return;
				}
				else if (map[i][j] == map[i][m] + map[m][j])
				{
					temp[i][j] = false;
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> N;
	for (int i = 0;i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = true;
		}
	}
	floyd();
	
	for (int i = 0;i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (temp[i][j] == true)
			{
				ans += map[i][j];
			}
		}
	}
	ans = ans / 2;
	if (isgo)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}

}