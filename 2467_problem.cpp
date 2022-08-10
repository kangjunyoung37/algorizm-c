#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<long long> water;
int Start = 0, End;
vector<pair<long, long>> ans;
long long result = 10e9;
void binary()
{
	End = water.size()-1;
	while (Start < End)
	{
		int Middle =  Start + (End-Start) / 2;

		if (water[Start] + water[End] < 0 )
		{
			
			if (result > abs(water[Start] + water[End]))
			{
				ans[0].first = water[Start];
				ans[0].second = water[End];
				result = abs(water[Start] + water[End]);
			}
			Start += 1;
		}
		else if (water[Start] + water[End] > 0)
		{
			
			if (result > abs(water[Start] + water[End]))
			{
				ans[0].first = water[Start];
				ans[0].second = water[End];
				result = abs(water[Start] + water[End]);
			}
			End -= 1;
		}
	
		else if (abs(water[Start] + water[End] == 0))
		{
			ans[0].first = water[Start];
			ans[0].second = water[End];
			return;
		}

	}


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		long long a;
		cin >> a;
		water.push_back(a);
	}
	sort(water.begin(), water.end());
	
	/*for (int i = 0; i < N; i++)
	{
		cout << water[i] << " ";
	}*/
	ans.push_back({ 0,0 });
	binary();
	
	cout << ans[0].first << " "<<ans[0].second;
}