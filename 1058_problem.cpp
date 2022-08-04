#include<iostream>
#include<string>
using namespace std;
int N;
string map[51];
int board[51][51];
void floyd()
{
	for (int m = 0; m < N; m++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (board[i][j] > board[i][m] + board[m][j])
				{
					board[i][j] = board[i][m] + board[m][j];
				}

			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = 10e7;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'Y')
			{
				board[i][j] = 1;
			}
		}
	}
	floyd();
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] <= 2)
			{
				cnt += 1;
			}
		}
		if (result < cnt)
		{
			result = cnt;
		}

	}
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << board[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	cout << result;

	
}