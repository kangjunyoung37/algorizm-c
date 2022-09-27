#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<int> progresses = {95,90,99,99,89,99};
	vector<int> speeds = {1,1,1,1,1,1};

	vector<int> answer;
	queue<int> time;
	for (int i = 0; i < progresses.size(); i++)
	{
		int a = 100 - progresses[i];
		int cnt = 0;
		while (a > 0)
		{
			a -= speeds[i];
			cnt++;
		}
		time.push(cnt);
	}
	int cnt = 1;
	int num = time.front();
	time.pop();
	while (!time.empty())
	{	
		if (num < time.front())
		{
			num = time.front();
			time.pop();
			answer.push_back(cnt);
			cnt = 1;
		}
		else
		{
			time.pop();
			cnt++;
		}		
	}
	if (cnt != 0)
	{
		answer.push_back(cnt);
	}

}