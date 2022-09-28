#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<int> citations;
	citations.push_back(3);
	citations.push_back(0);
	citations.push_back(6);
	citations.push_back(1);
	citations.push_back(6);



	int answer = 0;
	sort(citations.begin(), citations.end(),greater<int>());

	for (int i = 0; i < citations.size() ;i++)
	{
		cout << citations[i];
	}
	for (int i = 0; i < citations.size(); i++)
	{
		if (citations[i] > i)
		{
			answer++;
		}
		else
		{
			break;
		}
	}
	cout << answer;

}