#include<iostream>
#include<vector>
using namespace std;

int parent[100001];
vector<vector<int>> edge(100001);
int N;
void FindParent(int node) {
	for (int i = 0; i < edge[node].size(); i++)
	{
		if (parent[edge[node][i]] == 0)
		{
			parent[edge[node][i]] = node;
			FindParent(edge[node][i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	FindParent(1);

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}

}