#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;

int Parent[100001];
int FindParent(int son)
{
	if (Parent[son] == son)
	{
		return son;
	}
	return Parent[son] = FindParent(Parent[son]);
}

bool Union_(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);
	if (a == b)
	{
		return false;
	}
	Parent[b] = a;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N, M;
	cin >> N >> M;
	long long sum = 0;
	vector<tuple<int, int, int>> map;
	for (int i = 1; i <= N; i++)
	{
		Parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map.push_back({ d,x,y });
		map.push_back({ d,y,x });
		sum += d;
	}

	sort(map.begin(), map.end());

	for (int i = 0; i < map.size();i++)
	{
		int d = get<0>(map[i]);
		int x = get<1>(map[i]);
		int y = get<2>(map[i]);
		if (Union_(x, y))
		{
			sum -= d;
		}
	}
	int a = FindParent(1);
	for (int i = 1; i <= N; i++)
	{
		if (a != FindParent(i))
		{
			cout << -1;
			return 0;
		}
	}
	cout << sum;
	
}