#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int visit[100002];
bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second < b.second)
	{
		return true;
	}
	else
		return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	vector<pair<int,int>> meeting;
	
	int N;
	cin >> N;
	int count = 1;
	
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		meeting.push_back(make_pair(a, b));
	}
	sort(meeting.begin(), meeting.end());
	sort(meeting.begin(), meeting.end(),comp);

	/*for (int i = 0; i < N; i++)
	{
		cout << meeting[i].first << " " << meeting[i].second << "\n";
	}*/

	
	int lasttime = meeting[0].second;

	for (int i = 1; i < N; i++)
	{
		int starttime = meeting[i].first;
		if (lasttime <= starttime)
		{
			lasttime = meeting[i].second;
			count++;
		}
	

	}
	cout << count;

}