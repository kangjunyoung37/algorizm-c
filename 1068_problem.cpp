#include<iostream>
#include<vector>
using namespace std;

vector<int> map[51];
int num,cnt = 0;
void dfs(int root)
{
	if (root == num)
	{
		return;
	}
	for (int i = 0; i < map[root].size(); i++)
	{
		int a = map[root][i];
		if (a != num && map[a].size() == 0)
		{
			cnt += 1;
		}
		else if (a == num && map[root].size() == 1)
		{
			cnt += 1;
		}
		dfs(a);
		
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int root = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a == -1)
		{
			root = i;
			continue;
		}
		map[a].push_back(i);
	}

	
	cin >> num;

	dfs(root);
	cout << cnt;

}