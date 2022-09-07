#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Edge[10001];
int check[10001];
int hacking[10001];
int N, M;
int sum = 0, maxest = 0;
int Ans;
void dfs(int a)
{
	check[a] = 1;
	sum += 1;
	for (int i = 0; i < Edge[a].size(); i++)
	{
		if (check[Edge[a][i]])
		{
			continue;
		}
		dfs(Edge[a][i]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Edge[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		sum = 0;
		dfs(i);
		hacking[i] = sum;
		if (maxest < sum)
		{
			maxest = sum;
		}
		for (int i = 1; i <= N; i++)
		{
			check[i] = 0;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (hacking[i] == maxest)
		{
			cout << i << " ";
		}
	}

	
}