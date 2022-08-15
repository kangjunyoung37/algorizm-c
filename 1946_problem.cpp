#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int num;
	cin >> num;
	for (int k = 0; k < num; k++)
	{
		vector<pair<int, int>> grade;
		int n;
		cin >> n;
		int onestgrade;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			if (a == 1)
			{
				onestgrade = b;

			}
			grade.push_back({ a,b });
		}
		sort(grade.begin(), grade.end());
		int result = 1;
		for (int i = 1; i < grade.size();i++)
		{
			if (grade[i].second < onestgrade)
			{
				result += 1;
				onestgrade = grade[i].second;
			}
		}
		cout << result << "\n";
	}
}