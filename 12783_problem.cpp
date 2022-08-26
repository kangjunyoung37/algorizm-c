#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<long long> map;
	for (int i = 0; i < N; i++)
	{
		long long a;
		cin >> a;
		map.push_back(a);

	}
	vector<int> ans;
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		if (ans.size() == 0)
		{
			ans.push_back(map[i]);
			result += 1;
		}
		else
		{
			int a = lower_bound(ans.begin(), ans.end(), map[i]) - ans.begin();
			if (a == ans.size())
			{
				ans.push_back(map[i]);
				result += 1;
			}
			else
			{
				ans[a] = map[i];
			}

		}

	}
	cout << result;

}