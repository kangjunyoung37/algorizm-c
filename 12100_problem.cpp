#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int N;
int cdx, cdy;
int result = 0;

void simul(int cnt, vector<vector<int>> map)
{
	
	//if (cnt == 2)
	//{
	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < N; j++)
	//		{
	//			cout << map[i][j] << " ";
	//		}
	//		cout << "\n";
	//	}
	//	cout << "\n";
	//}
	int max_temp = 0;
	bool isgo = false;
	vector<vector<int>> tempmap = map;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (max_temp < tempmap[i][j])
			{
				max_temp = tempmap[i][j];
			}
		}
	}
	if (result < max_temp)
	{
		result = max_temp;
	}

	if (cnt > 5)
	{
		return;
	}

	// 오른쪽으로
	for (int i = 0; i < N; i++)
	{
		isgo = false;
		for (int j = N - 2; j >= 0; j--)
		{
			
			if (map[i][j] == 0)
			{
				continue;
			}
			int temp = map[i][j];
			map[i][j] = 0;
			for (int k = j + 1; k < N; k++)
			{
				if (map[i][k] > 0)
				{
					if (isgo == false && map[i][k] == temp)
					{
						map[i][k] = temp * 2;
						isgo = true;
						break;
					}
					else if (isgo == true || map[i][k] != temp)
					{
						map[i][k - 1] = temp;
						isgo = false;
						break;
					}
				}
				else if (map[i][k] == 0 && k == N - 1)
				{
					map[i][k] = temp;
					isgo = false;
					break;
				}
				
			}
		}
	}
	simul(cnt + 1, map);
	map = tempmap;

	// 왼쪽으로
	for (int i = 0; i < N; i++)
	{
		isgo = false;
		for (int j = 1; j < N; j++)
		{
			if (map[i][j] == 0)
			{
				continue;
			}
			int temp = map[i][j];
			map[i][j] = 0;
			for (int k = j-1; k >= 0; k--)
			{
				if (map[i][k] > 0)
				{
					if (isgo == false && map[i][k] == temp)
					{
						isgo = true;
						map[i][k] = temp * 2;
						break;
					}
					else if (isgo == true || map[i][k] != temp)
					{
						isgo = false;
						map[i][k + 1] = temp;
						break;
					}
				}
				else if (k == 0 && map[i][k] == 0)
				{
					map[i][k] = temp;
					isgo = false;
					break;
				}
			}
			
		}
	}
	simul(cnt + 1, map);
	map = tempmap;
	//위쪽으로

	for (int j = 0; j < N; j++)
	{
		isgo = false;
		for (int i = 1; i < N; i++)
		{
			if (map[i][j] == 0)
			{
				continue;
			}
			int temp = map[i][j];
			map[i][j] = 0;
			for (int k = i - 1; k >= 0; k--)
			{
				if (map[k][j] > 0)
				{
					if (isgo == false && map[k][j] == temp)
					{
						isgo = true;
						map[k][j] = temp * 2;
						break;
					}
					else if (isgo == true || map[k][j] != temp)
					{
						map[k + 1][j] = temp;
						isgo = false;		
						break;
					}
				}
				else if (k == 0 && map[k][j] == 0)
				{
					map[k][j] = temp;
					isgo = false;
					break;
				}

			}
		}
	}
	simul(cnt + 1, map);
	map = tempmap;

	//아래쪽
	for (int j = 0; j < N; j++)
	{
		isgo = false;
		for (int i = N - 2; i >= 0; i--)
		{
			if (map[i][j] == 0)
			{
				continue;
			}

			int temp = map[i][j];
			map[i][j] = 0;
			for (int k = i + 1; k < N; k++)
			{
				if (map[k][j] > 0)
				{
					if (isgo == false && map[k][j] == temp)
					{
						map[k][j] = temp * 2;
						isgo = true;
						break;
					}
					else if (isgo == true || map[k][j] != temp)
					{
						map[k - 1][j] = temp;
						isgo = false;
						break;
					}
				}
				else if (k == N - 1 && map[k][j] == 0)
				{
					map[k][j] = temp;
					isgo = false;
					break;
				}
			}
		}
	}
	simul(cnt + 1, map);
	map = tempmap;
	return;
	

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N,0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	simul(1, board);
	cout << result;

	 
}