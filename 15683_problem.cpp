#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//오른쪽 왼쪽 아래 위
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N, M;
vector<vector<int>> temp(9, vector<int>(9, 0));
int result = 987654321;
vector<pair<int, int>> pos;
int cdx, cdy;
void move1(int direction,int x , int y) //첫번째 cctv
{

	if (direction == 0)
	{
		while (1)
		{
			
			if ( y + dy[0] >= M ||temp[x][y + dy[0]] == 6 )
			{
				break;
			}
			if (temp[x][y + dy[0]] != 0 && temp[x][y + dy[0]] != 6)
			{
				y = y + dy[0];
				continue;
			}
			
			temp[x][y + dy[0]] = -1;
			y = y + dy[0];
		}
	
	}
	if (direction == 1)
	{
		while (1)
		{
			if (y + dy[1] < 0|| temp[x][y + dy[1]] == 6 )
			{
				break;
			}
			if (temp[x][y + dy[1]] != 0 && temp[x][y + dy[1]] != 6)
			{
				y = y + dy[1];
				continue;
			}
			temp[x][y + dy[1]] = -1;
			y = y + dy[1];
		}
	}
	if (direction == 2)
	{
		while (1)
		{
			if (x + dx[2] >= N || temp[x + dx[2]][y] == 6)
			{
				break;
			}
			if (temp[x + dx[2]][y] != 0 && temp[x + dx[2]][y] != 6)
			{
				x = x + dx[2];
				continue;
			}
			temp[x + dx[2]][y] = -1;
			x = x + dx[2];
		}
	}
	if (direction == 3)
	{
		while (1)
		{
			if (x + dx[3] < 0  || temp[x + dx[3]][y] == 6)
			{
				break;
			}
			if (temp[x + dx[3]][y] != 0 && temp[x + dx[3]][y] != 6)
			{
				x = x + dx[3];
				continue;
			}
			temp[x + dx[3]][y] = -1;
			x = x + dx[3];
		}
	}

}
void move2(int direction, int x, int y) //두번째 cctv
{
	if (direction == 0)
	{
		move1(0, x, y);
		move1(1, x, y);
	}

	if (direction == 1)
	{
		move1(2, x, y);
		move1(3, x, y);
	}
}
void move3(int direction, int x, int y)
{
	if (direction == 0)
	{
		//0,3
		move1(0, x, y);
		move1(3, x, y);
	}
	if (direction == 1)
	{
		//3,1
		move1(1, x, y);
		move1(3, x, y);
	}
	if (direction == 2)
	{
		//1,2
		move1(1, x, y);
		move1(2, x, y);
	}
	if (direction == 3)
	{
		//2,0
		move1(2, x, y);
		move1(0, x, y);
	}
}
void move4(int direction, int x, int y)
{
	if (direction == 0)
	{
		//0,1,2
		move1(0, x, y);
		move1(1, x, y);
		move1(2, x, y);

	}
	if (direction == 1)
	{
		//0,1,3
		move1(0, x, y);
		move1(1, x, y);
		move1(3, x, y);

	}
	if (direction == 2)
	{
		//1,2,3
		move1(1, x, y);
		move1(2, x, y);
		move1(3, x, y);

	}
	if (direction == 3)
	{
		//0,2,3
		move1(0, x, y);
		move1(2, x, y);
		move1(3, x, y);

	}
}
void move5(int x,int y)
{
	move1(0, x, y);
	move1(1, x, y);
	move1(2, x, y);
	move1(3, x, y);
}

void func(int num,vector<vector<int>> map)
{
	
	if (num == pos.size())
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
				{
					cnt += 1;
				}
			}
		}
		result = min(cnt, result);

		return;
	}

	int x = pos[num].first;
	int y = pos[num].second;

	if (temp[x][y] == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			temp = map;
			move1(i, x, y);
			func(num + 1,temp);

		}
	}

	else if (temp[x][y] == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			temp = map;
			move2(i, x, y);
			func(num + 1,temp);
	
		}
	}
	else if (temp[x][y] == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			temp = map;
			move3(i, x, y);
			func(num + 1, temp);
	
		}
	}
	else if (temp[x][y] == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			temp = map;
			move4(i, x, y);
			func(num + 1,temp);
		
		}
	}
	else if (temp[x][y] == 5)
	{
		temp = map;
		move5(x, y);
		func(num + 1,temp);
		
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> temp[i][j];
			if (temp[i][j] != 0 && temp[i][j] != 6)
			{
				pos.push_back(make_pair(i, j));
			}
		}
	}

	func(0,temp);
	cout << result;

}