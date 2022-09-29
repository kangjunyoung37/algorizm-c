#include<iostream>
#include<string>
#include<vector>
#define INF 987654321
using namespace std;

int dp[220][220][2];
vector<int> num;
vector<string> op;

int func(int st, int ed, int IsMax)
{
	int& result = dp[st][ed][IsMax];
	
	if (result != -1)
	{
		return dp[st][ed][IsMax];
	}
	if (st == ed)
	{
		return result = num[st];
	}
	if (IsMax)
	{
		result = -INF;
	}
	else
	{
		result = INF;
	}
	for (int i = st; i < ed; i++)
	{
		if (op[i] == "-")
		{
			if (IsMax)
			{
				result = max(result, func(st, i, true) - func(i + 1, ed, false));
			}
			else
			{
				result = min(result, func(st, i, false) - func(i + 1, ed, true));
			}
		}
		else
		{
			if (IsMax)
			{
				result = max(result, func(st, i, true) + func(i + 1, ed, true));
				
			}
			else
			{
				result = min(result, func(st, i, false) + func(i + 1, ed, false));
			}
		}
	}
	return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<string> arr = { "1", "-", "3", "+", "5", "-", "8" };
	
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < arr.size(); i++)
	{
		if (i % 2 == 0)
		{
			num.push_back(stoi(arr[i]));
		}
		else
		{
			op.push_back(arr[i]);
		}
	}
	int answer = func(0, arr.size()/2, true);
	cout << answer;

	
}