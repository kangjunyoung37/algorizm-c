#include<iostream>
#include<vector>

using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<int>> map(51, vector<int>(51, 0));
vector<pair<int, int>> air;
vector<vector<int>> temp(51, vector<int>(51, 0));
int R, C, T , cnt ,cdi ,cdj;
int x, y, x2, y2;
void spread(vector<vector<int>> board)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] > 4)
			{
				cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					cdi = i + dx[k];
					cdj = j + dy[k];
					if (cdi < 0 || cdj < 0 || cdi >= R || cdj >= C)
					{
						continue;
					}
					if (map[cdi][cdj] != -1)
					{
						board[cdi][cdj] += (map[i][j] / 5);
						cnt += 1;
					}
				}
				map[i][j] -= (map[i][j] / 5) * cnt;
			}
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			map[i][j] += board[i][j];
		}
	}
}
int count() {
	int count = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == -1)
			{
				continue;
			}
			count += map[i][j];
		}
	}
	return count;
}
void airmove(vector<vector<int>> copy)
{
	x = air[0].first;
	y = air[0].second;
	x2 = air[1].first;
	y2 = air[1].second;

	map[x][y + 1] = 0;
	map[x2][y2 + 1] = 0;
	map[x2 + 1][0] = 0;
	map[x - 1][0] = 0;
	for (int i = 2; i < C; i++)//오른쪽
	{
		map[x][i] = copy[x][i - 1];
		map[x2][i] = copy[x2][i - 1];
	}
	for (int i = x - 1;i >= 0; i--)//위
	{
		map[i][C - 1] = copy[i + 1][C - 1];
	}
	for (int i = R - 2;i > x2; i--)
	{
		map[i][0] = copy[i + 1][0];
	}
	for (int i = x2 + 1; i < R; i++)//아래
	{
		map[i][C - 1] = copy[i - 1][C - 1];
	}
	for (int i = 1; i < x;  i++)
	{
		map[i][0] = copy[i - 1][0];
	}
	for (int i = C-2; i >=0; i--)//왼쪽
	{
		map[0][i] = copy[0][i + 1];
		map[R - 1][i] = copy[R - 1][i + 1];
	}

	
}

	

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				air.push_back({ i,j });
			}
		}
	}
	while (T--)
	{
		spread(temp);
		airmove(map);
	}
	cout << count();
	/*cout << "\n";
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{

			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/
}