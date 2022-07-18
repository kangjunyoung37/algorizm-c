#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int map[21][21];
int N;
int ans = 987654321;
vector<int> temp; 

int sum1 = 0 , sum2 = 0;
void dfs(int x, int start)
{
	if (x == N/2)
	{
		sum1 = 0; sum2 = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (temp[i] == 1 && temp[j] == 1)
				{
					sum1 += map[i][j];
				}
				if (temp[i] == 0 && temp[j] == 0)
				{
					sum2 += map[i][j];
				}
			}
		}
		int result = abs(sum1 - sum2);
		if (ans > result)
		{
			ans = result;
		}

	}

	else
	{
		for (int i = start; i < N; i++)
		{
			temp[i] = 1;
			dfs(x + 1, i + 1);
			temp[i] = 0;
		}

	}
	return;
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
			cin >> map[i][j];
		}
	}
	for (int i = 0; i <= N; i++)
	{
		temp.push_back(0);
	}
	dfs(0, 1);
	cout << ans;

}