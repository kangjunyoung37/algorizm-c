#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> arr;
vector<int> d;
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
		d.push_back(0);
	}
	vector<int> l;
	for (int i = 0; i < n; i++)
	{
		int a = lower_bound(l.begin(), l.end(), arr[i]) - l.begin();
		if (a == l.size() || l.size() == 0)
		{
			l.push_back(arr[i]);		
		}
		l[a] = arr[i];
		d[i] = a;
	}
	int max_l = l.size() - 1;
	cout << l.size() << "\n";
	int x = d.size() - 1;
	vector<int> ans;
	while (x>=0)
	{
		if (d[x] == max_l)
		{
			ans.push_back(arr[x]);
			max_l--;
			x--;
		}
		else
		{
			x--;
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size();i++)
	{
		cout << ans[i] << " ";
	}

}

