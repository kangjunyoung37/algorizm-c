#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int visit[9];
int result[9],N,M;
vector<int> map;
void func(int x, int start)
{
	if (x == M)
	{
		for (int i = 0; i < M;i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i < N; i++)
	{
		if (visit[i])
			continue;
		result[x] = map[i];
		visit[i] = true;
		func(x + 1, i+1);
		visit[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		map.push_back(a);
	}
	sort(map.begin(), map.end());
	func(0, 0);
}