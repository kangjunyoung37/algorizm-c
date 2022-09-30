#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<int> priorities = { 2, 1, 3, 2 };
	int location = 2;
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++)
	{
		q.push({ priorities[i],i });
	}
	sort(priorities.begin(), priorities.end(),greater<int>());
	int answer = 0;
	while (!q.empty())
	{
		int current = q.front().first;
		int pos = q.front().second;
		q.pop();
		if (priorities[answer] == current)
		{
			if (pos == location)
			{
				break;
			}
			answer++;
		}
		else
		{
			q.push({ current,pos });
		}
	}
	cout << answer + 1;

}