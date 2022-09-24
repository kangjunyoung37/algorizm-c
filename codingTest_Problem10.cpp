#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int dis[20001];
int MAX = 0;
vector<pair<int, int>> Edge[20001];
void dijestra(int start)
{
	dis[start] = 0;
	priority_queue<pair<int, int>> q;
	q.push({ 0,start });
	while (!q.empty())
	{
		int current = q.top().second;
		int distance = -q.top().first;
		q.pop();
		for (int i = 0; i < Edge[current].size(); i++)
		{
			int next = Edge[current][i].second;
			int nextdis = Edge[current][i].first + distance;
			if (dis[next] > nextdis)
			{
				dis[next] = nextdis;
				q.push({ -nextdis,next });
				MAX = max(nextdis, MAX);
			}
		}
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	for (int i = 0; i < edge.size(); i++)
	{
		Edge[edge[i][0]].push_back({ 1,edge[i][1] });
		Edge[edge[i][1]].push_back({ 1,edge[i][0] });
	}

	fill(&dis[0], &dis[20001], INF);
	dijestra(1);
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] == MAX)
		{
			answer += 1;
		}
	}
	return answer;
}