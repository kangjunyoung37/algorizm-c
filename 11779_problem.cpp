#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 10e9+1
using namespace std;

long long dis[1001];
int n, m, Start, End;
vector<pair<int, int>> map[1001];
int root[1001];
void dijestra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dis[start] = 0;
	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (dis[current] < distance) continue;
		if (current == End) break;
		for (int i = 0; i < map[current].size();i++)
		{
			int nextdis = distance + map[current][i].first;
			int next = map[current][i].second;

			if (dis[next] > nextdis)
			{
				root[next] = current;
				dis[next] = nextdis;
				pq.push(make_pair(-nextdis, next));
			}	
			
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> m;

	for (int i = 0; i <= n; i++)
	{
		dis[i] = MAX;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x].push_back(make_pair(d,y));

	}
	
	cin >> Start >> End;
	dijestra(Start);
	//cout << dis[End] << "\n";
	//for (int i = 0; i <= n; i++)
	//{
	//	cout << dis[i] << " ";
	//}

	vector<int> ans;
	ans.push_back(End);
	int a = End;
	while (1)
	{
		if (Start == a)
		{
			break;
		}
		a = root[a];
		ans.push_back(a);
	}

	cout << dis[End] << "\n";

	cout << ans.size() << "\n";

	for (int i = ans.size()-1; i >= 0; i--)
	{
		cout << ans[i] << " ";
	}

}