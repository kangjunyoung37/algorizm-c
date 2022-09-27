#include<iostream>
#include<vector>
using namespace std;
int visit[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int answer = 0;
	int n = 5;
	vector<vector<int>> results;
	results.push_back({ 1,4 });
	results.push_back({ 4,2 });
	results.push_back({ 2,5 });
	results.push_back({ 5,3 });
	//results.push_back({ 2,5 });

	for (int i = 0; i < results.size(); i++)
	{
		visit[results[i][0]][results[i][1]] = 1;
		visit[results[i][1]][results[i][0]] = -1;
	}


	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (visit[i][k]  == 1 && visit[k][j] == 1)
				{
					visit[i][j] = 1;
				}
				else if (visit[i][k] == -1 && visit[k][j] == -1)
				{
					visit[i][j] = -1;
				}
			}
		}
	}
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (visit[i][j] == 0)
			{
				cnt ++;
			}
		}
		if (cnt == 1)
		{
			answer += 1;
		}
	}
	cout << answer;
}