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
	int answer = 0;
	vector<int> map(N,0);
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}
	vector<int> d;
	for (int i = 0; i < N; i++)
	{
		int a = lower_bound(d.begin(), d.end(), map[i]) - d.begin();
		if (a >= d.size())
		{
			d.push_back(map[i]);
			answer += 1;
		}
		else
		{
			d[a] = map[i];
		}

	}
	cout << answer;

	
}