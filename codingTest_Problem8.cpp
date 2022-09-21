#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	vector<int> numbers;

	int answer = 0;
	for (int i = 0; i < 4; i++)
	{
		int w;
		cin >> w;
		numbers.push_back(w);
	}
	int target;
	cin >> target;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty())
	{
		int x = q.front().first;
		int num = q.front().second;
		q.pop();
		if (x == numbers.size())
		{
			if (target == num)
			{
				answer += 1;
			}
			continue;
		}
		q.push({ x + 1,num + numbers[x] });
		q.push({ x + 1,num - numbers[x] });

	}
	cout << answer;

}