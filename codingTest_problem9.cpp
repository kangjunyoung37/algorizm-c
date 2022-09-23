#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	vector<int> times;
	long long answer = 0;
	long long maxtime = (long long)*min_element(times.begin(),times.end()) * n;
	long long mintime = 1;
	long long sum;
	while (mintime <= maxtime)
	{
		long long middletime = (maxtime + mintime) / 2;
		sum = 0;
		for (int i = 0; i < times.size(); i++)
		{
			sum += middletime / times[i];
		}
		if (sum >= n)
		{
			maxtime = middletime - 1;
			answer = middletime;
		}
		else
		{
			mintime = middletime + 1;
		}
	}
	
	return answer;
	
}