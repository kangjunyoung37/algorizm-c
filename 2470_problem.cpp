#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> map;
vector<pair<int, int>> resultxy;
long long result = 10e9;
long long temp = 0;
int Start = 0;
int End;
void binary()
{
	End = map.size() - 1;
	
	while (Start < End)
	{
		int Middle = (Start + End) / 2;
		temp = map[Start] + map[End ];
		
		if (temp == 0)
		{
			cout << map[Start] << " " << map[End];
			return;
		}
		if (result > abs(temp))
		{
			result = abs(temp);
			resultxy.push_back(make_pair(map[Start], map[End]));

		}
		if (temp > 0)
		{
			End --;
		}
		else
		{
			Start++;
		}
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		map.push_back(a);
	}
	sort(map.begin(), map.end());
	binary();
	cout << resultxy[resultxy.size() - 1].first << " " << resultxy[resultxy.size() - 1].second;

}