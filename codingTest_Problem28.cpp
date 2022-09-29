#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;


bool visit[201];
vector<vector<int>> computers;
void bfs(int a, vector<vector<int>> computers)
{
	visit[a] = true;
	queue<int> q;
	q.push(a);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < computers[cur].size(); i++)
		{
			if (i == cur)
			{
				continue;
			}
			if (computers[cur][i] == 1 && visit[i] == false)
			{
				visit[i] = true;
				q.push(i);
			}

		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	vector<vector<int>> computers;
	int answer = 0;
	computers.push_back({ 1,1,0 });
	computers.push_back({ 1,1,1 });
	computers.push_back({ 0,1,1 });
	for (int i = 0; i < computers.size(); i++)
	{
		if (visit[i])
		{
			continue;
		}
		answer++;
		bfs(i,computers);

	}
	cout << answer;

}