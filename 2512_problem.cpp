#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> money;
	int N; 
	int totalmoney;
	int start = 0;
	int end;
	int result = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		money.push_back(a);
	}
	sort(money.begin(), money.end());
	cin >> totalmoney;
	end = money[N-1];
	while (start <= end)
	{
		int middle = (start + end) / 2;

		int sum = 0;
		for (int i = 0; i < money.size();i++)
		{
			if (money[i] < middle)
			{
				sum += money[i];
			}
			else
			{
				sum += middle;
			}
		}
		if (sum > totalmoney)
		{
			end = middle - 1;
		}
		else if (sum < totalmoney)
		{
			result = max(result, middle);
			start = middle + 1;
		}
		else if (sum == totalmoney)
		{
			result = middle;
			break;
		}

	}
	cout << result;


}