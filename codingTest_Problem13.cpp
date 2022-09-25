#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	vector<vector<int>> jobs;

	sort(jobs.begin(), jobs.end());
	int j = 0;
	int time = 0;
	int sum = 0;
	while (j < jobs.size() || !q.empty())
	{
		if (jobs.size() > j && time >= jobs[j][0])
		{
			q.push({ jobs[j][1],jobs[j][0] });
			j++;
			continue;
		}
		if (!q.empty())
		{
			time += q.top().first;
			sum += time - q.top().second;
			q.pop();
		}
		else
		{
			time = jobs[j][0];
		}
	}
	int answer = sum / jobs.size();

	return answer;
	
	
}