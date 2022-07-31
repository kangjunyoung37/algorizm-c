#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;

	
	for (int i = 0; i < N; i++)
	{
		int days;
		cin >> days;
		vector<int> day;
		int cnt = 0;
		long long temp = 0;
		long long result = 0;
		for (int j = 0; j < days; j++)
		{
			int price;
			cin >> price;
			day.push_back(price);
		}
		int max_value = -1;
		

		for (int j = day.size() - 1;j >= 0; j--)
		{
			if (max_value > day[j])
			{
				cnt += 1;
				temp += day[j];
				continue;
				
			}
			if (max_value <= day[j])
			{
				
				result += (cnt * max_value) - temp;
				max_value = day[j];
				cnt = 0;
				temp = 0;
				continue;
				
			}
		}
		result += (cnt * max_value) - temp;
		
		cout << result << "\n";
	}
}