#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

int Parent[301];
int non[301];
vector<tuple<int, int,int>> edge;
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
		return false;;
	}
	Parent[b] = a;
	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N, ans = 0;
	cin >> N;
	int cost;
	for (int i = 0; i <= N; i++)
	{

		Parent[i] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> cost;
		edge.push_back({ cost,0,i });
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int a;
			cin >> a;
			if (i == j)
			{
				continue;
			}
			edge.push_back({ a,i,j });

		}
		
	}

	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++)
	{
		int d = get<0>(edge[i]);
		int x = get<1>(edge[i]);
		int y = get<2>(edge[i]);

		if (Union_(x, y))
		{
			ans += d;
		}
	}

	
	cout << ans;

}