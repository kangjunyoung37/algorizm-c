#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<int> nums;
	unordered_set<int> s;
	int answer = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		s.insert(nums[i]);
	}
	if (nums.size() / 2 < s.size())
	{
		answer = nums.size() / 2;
	}
	else
	{
		answer = s.size();
	}

	cout << answer;
}