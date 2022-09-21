#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	vector<vector<int>> sizes;
	int answer = 0;
	int one = 0, two = 0;
	for (int i = 0; i < sizes.size();i++)
	{
		if (sizes[i][0] > sizes[i][1])
		{
			one = max(one, sizes[i][0]);
			two = max(two, sizes[i][1]);
		}
		else
		{
			one = max(one, sizes[i][1]);
			two = max(two, sizes[i][0]);
		}
	}
	answer = one * two;



}