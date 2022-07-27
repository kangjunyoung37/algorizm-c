#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int N, M;
int Parent[1001];
char school[1001];
vector<tuple<int, int, int>> map;
int FindParent(int a)
{
	if (Parent[a] == a)
	{
		return a;
	}
	return Parent[a] = FindParent(Parent[a]);

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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> school[i];
		Parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		if (school[x] == school[y])
		{
			continue;
		}
		map.push_back( { d, x, y });
	}
	sort(map.begin(), map.end());

	for (int i = 0; i < map.size();i++)
	{
		int x = get<1>(map[i]);
		int y = get<2>(map[i]);
		int d = get<0>(map[i]);

		x = FindParent(x);
		y = FindParent(y);
		if (x == y)
		{
			continue;
		}
		Union_(x, y);
		cnt += d;
	}
	int A = FindParent(1);
	for (int i = 1; i <= N; i++)
	{

		if (FindParent(Parent[i]) != A)
		{
			cout << -1;
			return 0;
		}
	}
	cout << cnt;
	//for (int i = 1; i <= N; i++)
	//{
	//	cout << Parent[i] << " ";
	//}
	//cout << "\n";
	//cout << FindParent(Parent[5]);
}