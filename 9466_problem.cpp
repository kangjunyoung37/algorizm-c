#include<iostream>
#include<vector>
using namespace std;


int student[100001];
int visited[100001];
vector<int> team;
int N;
int cnt = 0;
void dfs(int x)
{
	visited[x] = 1;
	team.push_back(x);
	int a = student[x];
	if (visited[a] == 1)
	{
		for (int i = 0; i < team.size(); i++)
		{
			if (team[i] == a)
			{
				int x = team.size() - i;
				cnt += x;
			}
		}
	}
	else
	{
		dfs(a);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int casenum;
	cin >> casenum;
	for (int c = 0; c < casenum; c++)
	{
	
		cin >> N;
		cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			visited[i] = 0;
			cin >> student[i];
		}
		for (int i = 1; i <= N; i++)
		{
			team.clear();
			if (visited[i] == 0)
			{
				dfs(i);
			}
		}
		int result = N - cnt;
		cout << result << "\n";

	}
}