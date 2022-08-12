#include<iostream>
#include<vector>
#include<queue>

using namespace std;

long long dis[10001];
vector<pair<int, int>> map[10001];
void dijestra(int start)
{
	priority_queue<pair<long long, int>> pq;
	pq.push({0,start});
	dis[start] = 0;
	while (!pq.empty())
	{
		int current = pq.top().second;
		long long distance = -pq.top().first;
		pq.pop();
		for (int i = 0; i < map[current].size();i++)
		{
			int next = map[current][i].second;
			long long nextdis = map[current][i].first + distance;

			if (dis[next] > nextdis)
			{
				dis[next] = nextdis;
				pq.push({ -nextdis, next });
			}
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int Num , n,  d,  c , ans = 0 ,cnt = 0;
	cin >> Num;
	for (int  z = 0; z < Num; z++)
	{
		
		fill(&dis[0], &dis[10001], 10e9);
		cin >> n >> d >> c;
		

		for (int i = 0; i < d; i++)
		{
			int x, y, d;
			cin >> x >> y >> d;
			//map[x].push_back({ d,y });
			map[y].push_back({d,x});
		}

		dijestra(c);
		cnt = 0;
		ans = 0;
		for (int i = 1; i <= n; i++)
		{

			if (dis[i] != 10e9)
			{
				cnt += 1;
				if (ans < dis[i])
				{
					ans = dis[i];
				}
			}
			
			
		}
		cout << cnt << " "<< ans << "\n";
		for (int i = 1; i <= n; i++)
		{
			map[i].clear();
		}
	}


}