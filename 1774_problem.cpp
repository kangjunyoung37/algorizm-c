#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>
#include<algorithm>
using namespace std;

int parent[1002];
vector<tuple<double, int, int>> edge;
int FindParent(int start)
{
	if (parent[start] == start)
		return start;
	return parent[start] = FindParent(parent[start]);
}
void Union_(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);
	if (a == b)
	{
		return;
	}
	parent[b] = a;

}
vector<pair<int,int>> map;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double ans = 0;
	int N, M;
	cin >> N >> M;
	map.push_back(make_pair(0, 0));
	for (int i = 1; i <= N; i++)
	{
		int x, y;
		cin >> x >> y;
		map.push_back(make_pair(x, y));
		parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Union_(a, b);
		
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (FindParent(i) != FindParent(j))
			{
				double x1 = map[i].first;
				double y1 = map[i].second;
				double x2 = map[j].first;
				double y2 = map[j].second;
				double disitance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
				edge.push_back({ disitance,i,j });
			}
		}
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++)
	{
		int a = get<1>(edge[i]);
		int b = get<2>(edge[i]);
		if (FindParent(a) != FindParent(b))
		{
			Union_(a, b);
			ans += get<0>(edge[i]);
		}

	}
	//cout.precision(3);
	printf("%.2f", ans);

}