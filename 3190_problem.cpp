#include<iostream>
#include<queue>
#include<vector>

#define MAX_V 102

using namespace std;
int board[MAX_V][MAX_V];
queue<pair<int, int>> warm;
vector<pair<int, char>> path;
//0왼쪽 1위쪽 2오른쪽 3아래쪽
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int N;//가로 세로 길이
int result = 1; //살아있는 시간
int second = 0;
bool move(int count ,int direction,queue<pair<int,int>>& warm)
{

	for (int i = 0; i < count; i++)
	{
		int tailx = warm.front().first;
		int taily = warm.front().second;
		int headx = warm.back().first;
		int heady = warm.back().second;

		int cdx = headx + dx[direction];
		int cdy = heady + dy[direction];

		if (cdx < 0 || cdx >= N || cdy < 0 || cdy >= N || board[cdx][cdy] == 2)
		{
			return false;
		}

		warm.push(make_pair(cdx, cdy));
				
		if (board[cdx][cdy] == 1)
		{
			board[cdx][cdy] = 2;
			
		}
		else if (board[cdx][cdy] == 0)
		{
			warm.pop();
			board[tailx][taily] = 0;
			board[cdx][cdy] = 2;
		}
		
		result++;
	}
	return true;
}
//L이면 왼쪽 D면 오른쪽
int main()
{
	board[0][0] = 2;
	int direction = 2;
	
	cin >> N;
	int apple;
	cin >> apple;

	warm.push(make_pair(0,0));
	
	for (int i = 0; i < apple; i++)//사과
	{
		int x, y;
		cin >> x >> y;
		board[x-1][y-1] = 1;

	}
	int root;
	cin >> root;

	for (int i = 0; i < root; i++) //경로
	{
		int count;
		char a;
		cin >> count >> a;
		path.push_back(make_pair(count, a));

	}
	int start = 0;
	for (int i = 0; i < root; i++)
	{
		
		if (!move(path[i].first - start, direction, warm)) break;
		start = path[i].first;

		if (path[i].second == 'D')
		{
 			direction = (direction + 1) % 4;
			continue;

		}
		
		if (path[i].second == 'L')
		{
			direction = (direction + 3) % 4;
			continue;
		}
		
			
	}
	move(200, direction, warm);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << result;
}
