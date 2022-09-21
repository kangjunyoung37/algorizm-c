#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	int student[31];
	vector<int> lost;
	vector<int> reserve;
	int answer = 0;
	fill(&student[0], &student[31], 1);
	for (int i = 0; i < lost.size(); i++)
	{
		student[lost[i]] -= 1;
	}
	for (int i = 0; i < reserve.size(); i++)
	{
		student[reserve[i]] += 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (student[i] == 2)
		{
			if (student[i - 1] == 0)
			{
				student[i - 1] = 1;
				student[i] = 1;
				continue;
			}
			if (student[i + 1] == 0)
			{
				student[i + 1] = 1;
				student[i] = 1;
				continue;
			}
		}
	}
	for (int i = 1; i <= n;i++)
	{
		if (student[i] >= 1)
		{
			answer += 1;
		}
	}

}