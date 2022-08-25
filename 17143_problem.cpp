#include<iostream>
#include<vector>
#include<algorithm>
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
	int num;
};
struct King { int r = 1, c = 0; } fishKing;
vector<shark> map[101][101] , sharks;


int N, M, num, ans = 0;

bool comp(const shark& a, const shark& b)
{
	return a.sharksize > b.sharksize;
}
void updateshark()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			map[i][j].clear();
		}
	}
	for (int i = 0; i < sharks.size(); i++)
	{
		map[sharks[i].x][sharks[i].y].push_back(sharks[i]);
	}
	sharks.clear();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!map[i][j].size())
			{
				continue;
			}
			sort(map[i][j].begin(), map[i][j].end(), comp);
			shark big = map[i][j][0];
			map[i][j].clear();
			map[i][j].push_back(big);
			sharks.push_back(big);
			
		}
	}
}

void moveFishKing() {
	fishKing.c++;
}

void Move()
{
	for (auto& s : sharks) {
		int nr = s.x;
		int nc = s.y;
		int iterRow = abs(dx[s.direction] * s.move);
		int iterCol = abs(dy[s.direction] * s.move);
		//위아래 초과
		for (int i = 0; i < iterRow; i++) {
			if (nr == 1 && s.direction == 1) s.direction = 2;
			if (nr == N && s.direction == 2) s.direction = 1;
			nr += dx[s.direction];
		}
		//좌우초과시 방향전환
		for (int i = 0; i < iterCol; i++) {
			if (nc == 1 && s.direction == 4) s.direction = 3;
			if (nc == M && s.direction == 3) s.direction = 4;
			nc += dy[s.direction];
		}
		s.x = nr;
		s.y = nc;
	}
}
void CatchPish()
{
	int sharkNum = -1;
	for (int i = 1; i <= N; i++) {
		if (map[i][fishKing.c].size()) {
			ans += map[i][fishKing.c][0].sharksize;
			sharkNum = map[i][fishKing.c][0].num;
			map[i][fishKing.c].clear();
			break;
		}
	}

	if (sharkNum >= 0) {
		for (auto s = sharks.begin(); s != sharks.end(); s++)
			if (s->num == sharkNum) { sharks.erase(s); break; }
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> M >> num;
	//sharks.resize(num);
	for (int i = 0; i < num; i++)
	{
		int x, y, move, diretion, sharksize;
		cin >> x >> y >> move >> diretion >> sharksize;
		shark a;
		a.x = x;
		a.y = y;
		a.move = move;
		a.direction = diretion;
		a.sharksize = sharksize;
		a.num = i;
		sharks.push_back(a);
		map[x][y].push_back(a);
		
	}
	for (int i = 1; i <= M; i++)
	{
		moveFishKing();
		CatchPish();
		Move();
		updateshark();
	}
	cout << ans;
}