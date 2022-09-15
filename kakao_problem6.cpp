#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };
int x, y;
int solution(int m, int n, vector<string> board) {

	int answer = 0;
	queue<pair<int, int>> pang;
	bool isgo;
	//찾기
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			isgo = true;
			for (int k = 0; k < 3; k++)
			{
				if (board[i][j] != board[i + dx[k]][j + dy[k]])
				{
					isgo = false;
					break;
				}
			}
			if (isgo)
			{
				pang.push({ i,j });
				for (int k = 0; k < 3; k++)
				{
					pang.push({ i + dx[k],j + dy[k] });
				}
			}
		}
	}
	while (!pang.empty())
	{
		//지우기
		while (!pang.empty())
		{
			x = pang.front().first;
			y = pang.front().second;
			pang.pop();
			if (board[x][y] == ' ')
			{
				continue;
			}
			board[x][y] = ' ';
			answer += 1;
		}
		//끌어내리기
		int a;
		for (int i = m - 2; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (board[i][j] == ' ')
				{
					continue;
				}
				if (board[i + 1][j] == ' ')
				{
					a = i + 1;
					while (a < m)
					{
						if (board[a][j] != ' ')
						{
							break;
						}
						a++;
					}
					board[a - 1][j] = board[i][j];
					board[i][j] = ' ';
				}
			}
		}
		//찾기
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (board[i][j] == ' ')
				{
					continue;
				}
				isgo = true;
				for (int k = 0; k < 3; k++)
				{
					if (board[i][j] != board[i + dx[k]][j + dy[k]])
					{
						isgo = false;
						break;
					}
				}
				if (isgo)
				{
					pang.push({ i,j });
					for (int k = 0; k < 3; k++)
					{
						pang.push({ i + dx[k],j + dy[k] });
					}
				}
			}
		}
	}
	return answer;
}