#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_D 987654321
using namespace std;

vector<pair<int, int>> map[2001];
int dis[2001];
int dis1[2001];
int cross1, cross2;
vector<int> ans;

void dijestra(int start)
{
	priority_queue<pair<int, int>> q;
	q.push({ 0,start });
	dis[start] = 0;
	while (!q.empty())
	{

		int current = q.top().second;
		int distance = -q.top().first;
		q.pop();
		for (int i = 0; i < map[current].size();i++)
		{
			int Next = map[current][i].second;
			int nexdis = map[current][i].first + distance;

			if (dis[Next] > nexdis)
			{
				dis[Next] = nexdis;
				q.push({ -nexdis,Next });
			}
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	for (int a = 0; a < T; a++)
	{
		vector<pair<int, int>> arr;
		int n, m, t;
		cin >> n >> m >> t;

		for (int i = 1; i <= n; i++)
		{
			map[i].clear();
		}
		ans.clear();
		fill(&dis[0], &dis[2001], MAX_D);


		int s, g, h;
		cin >> s >> g >> h; // 출발지, 가고있는곳
		int GHdistance = 0;
		for (int i = 0; i < m; i++)
		{
			int x, y, d;
			cin >> x >> y >> d;
			if (x == g && y == h || x == h && y == g)
			{
				GHdistance = d;
			}
			map[x].push_back({ d,y });
			map[y].push_back({ d,x });
		}
		dijestra(s);
		
		for (int i = 0; i < t; i++)
		{
			int b;
			cin >> b;
			arr.push_back({ b,0 });	
		}
		
		for (int i = 0; i < arr.size();i++)
		{
			arr[i].second = dis[arr[i].first];
		}
		if (dis[g] > dis[h])
		{
			cross1 = dis[h];
			fill(&dis[0], &dis[2001], MAX_D);
			dijestra(g);
			for (int i = 0; i < arr.size();i++)
			{
				if (arr[i].second == GHdistance  + cross1 + dis[arr[i].first])
				{
					ans.push_back(arr[i].first);
				}
			}
		}
		else
		{

			cross1 = dis[g];
			fill(&dis[0], &dis[2001], MAX_D);
			dijestra(h);
			for (int i = 0; i < arr.size();i++)
			{
				if (arr[i].second == GHdistance  + cross1 + dis[arr[i].first])
				{
					ans.push_back(arr[i].first);
				}
			}
			
		}
		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size();i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
		

		//for (int i = 0; i <= n; i++)
		//{
		//	cout << dis[i] << " ";
		//}

	}

}