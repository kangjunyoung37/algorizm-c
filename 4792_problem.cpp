#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int Parent[1001];
int n, m, k;
int FindParent(int son)
{
	if (Parent[son] == son)
	{
		return son;
	}
	return FindParent(Parent[son]);
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
struct Edge
{
	int x;
	int y;
	int c;
	bool operator<(const Edge& a)
	{
		return c < a.c;
	}
};

int kruskal(vector<Edge> a)
{

	for (int i = 1; i <= n; i++) Parent[i] = i;
	sort(a.begin(), a.end());
	int cnt = 0; int cost = 0;
	for (int i = 0; i < a.size();i++)
	{
		int x = a[i].x;
		int y = a[i].y;
		int c = a[i].c;
		if (FindParent(x) == FindParent(y))
		{
			continue;
		}
		if (Union_(x, y))
		{
			cnt += 1;
			cost += c;
		}
		if (cnt == n - 1)
		{
			return cost;
		}
	}
	return cost;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	while (1)
	{
		
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0) break;
		

		vector<Edge> min_blue;
		vector<Edge> max_blue;
		for (int i = 0; i < m; i++)
		{
			char c;
			int  x, y;
			cin >> c >> x >> y;

			if (c == 'R')
			{
				min_blue.push_back({ x,y,0 });
				max_blue.push_back({ x,y,1 });
			}
			else
			{
				max_blue.push_back({ x,y,0 });
				min_blue.push_back({ x,y,1 });
			}

		}
		int min_v = kruskal(min_blue);
		int max_v = (n-1) - kruskal(max_blue);
		if (min_v <= k && max_v >= k)
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	

	}
}