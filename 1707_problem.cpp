#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V, E, K;

vector<int> map[20001];
int group[20001];

bool bfs(int a)
{

	queue<int> q;
	q.push(a);
	group[a] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int k = 0; k < map[x].size();k++)
		{

			if (!group[map[x][k]])
			{
				q.push(map[x][k]);
				group[map[x][k]] = -group[x];
			}
			else
			{
				if (group[map[x][k]] == group[x])
				{
					//cout << "NO" << "\n";
					return false;
				}
			}


		}
		
	}
	//cout << "YES" << "\n";
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> K;
	for (int i = 0; i < K; i++)
	{

		cin >> V >> E;

		for (int j = 0; j < E; j++)
		{
			int x, y;
			cin >> x >> y;
			map[x].push_back(y);
			map[y].push_back(x);
		}

		bool answer = true;
		for (int j = 1;j <= V;j++)
		{
			if (group[j] == 0)
			{
				if (!bfs(j))
				{
					answer = false;
					break;
				}
			}

		}
		if (answer)
		{
			cout << "YES" << "\n";

		}
		else
		{
			cout << "NO" << "\n";
		}
		for (int m = 1; m <= V; m++)
		{
			map[m].clear();
			group[m] = 0;
		}
	

	}

}