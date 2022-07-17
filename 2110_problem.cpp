#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> house;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, C, result;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		house.push_back(a);
	}
	sort(house.begin(), house.end());
	int left = 1;
	int right = house[N - 1];
	while (left <= right)
	{
		int install = 1;
		int mid = (left + right) / 2;

		int Start = house[0];
		for (int i = 1; i < N; i++)
		{
			if (house[i] - Start >= mid)
			{
				install += 1;
				Start = house[i];
			}
		}
		if (install >= C)
		{
			
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}



	}
	cout << result;
}