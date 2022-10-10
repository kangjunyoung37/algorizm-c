#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> edge[100001];
bool visit[100001];
int root;
int maxdistance = 0;
void func(int prev,int current,int node)
{
	if (maxdistance < current)
	{
		maxdistance = current;
		root = node;
	}
	visit[node] = true;
	for (int i = 0; i < edge[node].size(); i++)
	{
		if (visit[edge[node][i].first])
			continue;
		func(current, current + edge[node][i].second, edge[node][i].first);
		
	}
	visit[node] = false;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		while (1)
		{
			int b, d;
			cin >> b;
			
			if (b == -1)
			{
				break;
			}
			cin >> d;
			edge[a].push_back({ b,d });
		}
	}
	func(0, 0, 1);
	maxdistance = 0;
	func(0, 0, root);
	cout << maxdistance;
}