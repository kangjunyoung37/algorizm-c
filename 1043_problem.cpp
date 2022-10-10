#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> graph;
bool check[51];
void bfs(int num)
{
	for (int i = 0; i < graph.size(); i++)
	{
		if (check[i])
		{
			continue;
		}
		for (int j = 0; j < graph[i].size(); j++)
		{
			if (graph[i][j] == num)
			{
				check[i] = true;
				for (int k = 0; k < graph[i].size(); k++)
				{
					if (j == k)
					{
						continue;
					}
					bfs(graph[i][k]);
				}
				break;
			}
			
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N >> M;
	int num;
	cin >> num;
	vector<int> TruePeople;
	for (int i = 0; i < num; i++)
	{
		int a;
		cin >> a;
		TruePeople.push_back(a);
	}
	for (int i = 0; i < M; i++)
	{
		vector<int>temp;
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			int b;
			cin >> b;
			temp.push_back(b);
		}
		graph.push_back(temp);
	}
	for (int i = 0; i < TruePeople.size(); i++)
	{
		bfs(TruePeople[i]);
	}
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		if (check[i] == 0)
		{
			ans += 1;
		}
	}
	cout << ans;



}