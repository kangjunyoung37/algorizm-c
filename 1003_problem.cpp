#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> d;

void find(vector<pair<int, int>>& d, int n)
{
	d.push_back( { d[n - 1].first + d[n - 2].first, d[n - 1].second + d[n - 2].second }) ;

}
int main() {

	int cnt;
	cin >> cnt;
	vector<int> index;

	for (int i = 0; i < cnt; i++)
	{
		int a;
		cin >> a;
		index.push_back(a);
	}
	d.push_back({ 1, 0 });
	d.push_back({ 0,1 });

	//d[n] = d[n-1] + d[n-2]
	int max = *max_element(index.begin(), index.end());
	for (int i = 2; i <= max; i++)
	{
		find(d, i);
	}
	for (int i = 0; i < index.size();i++)
	{
		cout << d[index[i]].first << ' ' << d[index[i]].second << '\n';
	}

	
}