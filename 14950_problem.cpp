#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;

int Parent[10001];

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

vector<tuple<int, int, int>> map;
int main()

{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int num = 0;
	int ans = 0;
	int N, M, t;
	cin >> N >> M >> t;
	for (int i = 0; i <= N; i++)
	{
		Parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map.push_back({ d,x,y });
		map.push_back({ d,y,x });
	}
	sort(map.begin(), map.end());

	for (int i = 0; i < map.size(); i++)
	{
		int a, b, d;
		d = get<0>(map[i]);
		a = get<1>(map[i]);
		b = get<2>(map[i]);
		if (Union_(a, b))
		{
			ans += (num * t) + d;
			num++;
		}
	}
	cout << ans;
}