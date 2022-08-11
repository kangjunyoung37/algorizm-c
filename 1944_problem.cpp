#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
char map[51][51];
int map_node[51][51];
int N, K;
int visit[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int Parent[251];
int ans = 0;
int cnt1 = 0;
void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = 0;
		}
	}
}
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
		return false;
	}
	Parent[b] = a;
	return true;
}
struct robot
{
	int x;
	int y;
	int length;
};

vector<pair<int, int>> pos;
vector<robot> robotmap;

bool comp(const robot& a, const robot& b)
{
	return a.length < b.length;
}

void bfs(int x, int y)
{
	init();
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = 1;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cdx = cx + dx[i];
			int cdy = cy + dy[i];
			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= N)
			{
				continue;
			}

			if (map[cdx][cdy] != '1' && visit[cdx][cdy] == 0)
			{
				visit[cdx][cdy] = visit[cx][cy] + 1;
				q.push({ cdx,cdy });
				if (map[cdx][cdy] == 'S' || map[cdx][cdy] == 'K')
				{
					robot robot1;
					robot1.x = map_node[x][y];
					robot1.y = map_node[cdx][cdy];
					robot1.length = visit[cdx][cdy] - 1;
					robotmap.push_back(robot1);

				}

			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			
			if (map[i][j] == 'K' || map[i][j] == 'S')
			{
				cnt += 1;
				pos.push_back({ i,j });
				map_node[i][j] = cnt;
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		Parent[i] = i;
	}
	/*for (int i = 0;i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map_node[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i = 0; i < pos.size();i++)
	{
		bfs(pos[i].first, pos[i].second);
	}
	sort(robotmap.begin(), robotmap.end(), comp);

	for (int i = 0; i < robotmap.size();i++)
	{
		int x = robotmap[i].x, y = robotmap[i].y, length = robotmap[i].length;
		if (Union_(x, y))
		{
			ans += length;
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		if (Parent[i] == i)
		{
			cnt1 += 1;
		}
		if (cnt1 > 1)
		{
			ans = -1;
			break;
		}
	}
	cout << ans;
}