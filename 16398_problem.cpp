#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;


int parent[1001];
int FindParent(int son)
{
	if (parent[son] == son)
		return son;
	return parent[son] = FindParent(parent[son]);
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

int N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int a,x,y,d;
	long long result = 0;
	vector<tuple<int,int,int>> graph;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a;
			if (i > j)
			{
				graph.push_back({ a,i,j });
	
			}
		}
		parent[i] = i;
	}

	sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); i++)
	{
		d = get<0>(graph[i]);
		x = get<1>(graph[i]);
		y = get<2>(graph[i]);
		if (FindParent(x) == FindParent(y))
		{
			continue;
		}
		Union_(x, y);
		result += d;
	}
	cout << result;
}