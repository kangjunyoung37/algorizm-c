#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int Parent[1001];
vector<tuple<int, int, int>> map;
int FindParent(int son)
{
	if (Parent[son] == son)
	{
		return son;
	}
	return FindParent(Parent[son]);
}
void Union_(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);
	if (a == b)
	{
		return;
	}
	Parent[b] = a;

}
bool comp(tuple<int, int, int>& a, tuple<int, int, int>& b)
{	
	return get<0>(a) > get<0>(b);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
	{
		Parent[i] = i;
	}

	for (int i = 0; i < M + 1; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map.push_back({ d,x,y });
	}
	sort(map.begin(), map.end());
	//sort(map.begin(), map.end(), comp);

	/*for (int i = 0; i < M + 1;i++)
	{
		int a = get<0>(map[i]);
		int b = get<1>(map[i]);
		int c = get<2>(map[i]);
		cout << a << " " << b << " " << c << "\n";
	}*/
	int cnt = 0;
	int tiredlong;
	int tiredshort;
	for (int i = 0; i < M + 1;i++)
	{
		int c = get<0>(map[i]);
		int a = get<1>(map[i]);
		int b = get<2>(map[i]);
		if (FindParent(a) == FindParent(b))
		{
			continue;
		}
		Union_(a, b);
		if (c == 0)
		{
			cnt += 1;
		}
		tiredlong = cnt * cnt;
		
	}
	cnt = 0;
	for (int i = 0; i <= N; i++)
	{
		Parent[i] = i;
	}
	for (int i = M; i >= 0; i--)
	{
		int c = get<0>(map[i]);
		int a = get<1>(map[i]);
		int b = get<2>(map[i]);
		if (FindParent(a) == FindParent(b))
		{
			continue;
		}
		Union_(a, b);
		if (c == 0)
		{
			cnt += 1;
		}
		tiredshort = cnt * cnt;
	}
	cout << tiredlong - tiredshort;

}