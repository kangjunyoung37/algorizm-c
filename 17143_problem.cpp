#include<iostream>
#include<vector>
using namespace std;
//위 아래 오른 왼
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
struct shark {
	int x;
	int y;
	int sharksize;
	int direction;
	int move;
};

int N, M, num, ans = 0;
vector<shark> sharks;
vector<shark> live;
int map[101][101];


void Move()
{
	for (int i = 0; i < sharks.size(); i++)
	{
		int b = sharks[i].move;
		while (b--)
		{
			sharks[i].x += dx[sharks[i].direction];
			sharks[i].y += dy[sharks[i].direction];
			if (sharks[i].x > N)
			{
				sharks[i].x = N - 1;
				//sharks[i].direction -= 1;
				sharks[i].direction = 1;
				continue;
			}
			else if (sharks[i].x < 1)
			{
				sharks[i].x = 2;
				//sharks[i].direction += 1;
				sharks[i].direction = 2;

				continue;
			}
			if (sharks[i].y > M)
			{
				sharks[i].y = M - 1;
				//sharks[i].direction += 1;
				sharks[i].direction = 4;
				continue;
			}
			else if (sharks[i].y < 1)
			{
				sharks[i].y = 2;
				//sharks[i].direction -= 1;
				sharks[i].direction = 3;
				continue;
			}
			

		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = -1;
		}
	}
	live.clear();
	for (int i = 0; i < sharks.size(); i++)
	{
		if (map[sharks[i].x][sharks[i].y] != -1)
		{
			if (sharks[map[sharks[i].x][sharks[i].y]].sharksize > sharks[i].sharksize)
			{
				continue;
			}
			else
			{
				live[map[sharks[i].x][sharks[i].y]] = sharks[i];
			}
		}
		else
		{
			map[sharks[i].x][sharks[i].y] = live.size();
			live.push_back(sharks[i]);
		}
		
	}
}

void simul()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = -1;
		}
	}
	for (int i = 0; i < sharks.size(); i++)
	{
		if (map[sharks[i].x][sharks[i].y] != -1)
		{
			if (sharks[map[sharks[i].x][sharks[i].y]].sharksize > sharks[i].sharksize)
			{
				continue;
			}
			else
			{
				live[map[sharks[i].x][sharks[i].y]] = sharks[i];
			}
		}
		else
		{
			map[sharks[i].x][sharks[i].y] = live.size();
			live.push_back(sharks[i]);
		}

	}
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{

			if (map[j][i] != -1)
			{
				ans += live[map[j][i]].sharksize;
				live.erase(live.begin() + map[j][i]);
				sharks = live;
				break;
			}
		}
		Move();

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> M >> num;

	for (int i = 0; i < num; i++)
	{
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		map[x][y] = i;
		shark a;
		a.x = x;
		a.y = y;
		a.move = s;
		a.direction = d;
		a.sharksize = z;
		sharks.push_back(a);

	}


	simul();
	cout << ans;
}