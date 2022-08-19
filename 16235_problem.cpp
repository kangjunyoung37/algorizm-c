#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, K;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };
vector<int> map[11][11];
int winter[11][11];
int tree[11][11];
queue<pair<int, int>> pos;

void simul(vector<int> board[11][11])
{
	int a = pos.size();
	while (a > 0)
	{
		a--;
		int x = pos.front().first;
		int y = pos.front().second;
		pos.pop();
		int sum = 0;
		bool isgo = false;
		sort(board[x][y].begin(), board[x][y].end());
		for (int k = 0; k < board[x][y].size(); k++)
		{
			
			if (board[x][y][k] == 0)
				continue;
			
			if (board[x][y][k] <= tree[x][y])
			{
				tree[x][y] -= board[x][y][k];
				map[x][y][k] += 1;
				isgo = true;
			}
			else
			{
				sum += (board[x][y][k] / 2);
				map[x][y][k] = 0;
			}		
 		}
		/*if (isgo)
		{
			pos.push({ x,y });
		}*/

		tree[x][y] += sum;
		

		
		for (int k = 0; k < map[x][y].size(); k++)
		{
			if (map[x][y][k] == 0)
				continue;
			if (map[x][y][k] % 5 == 0)
			{
				for (int i = 0;i < 8; i++)
				{
					int cdx = x + dx[i];
					int cdy = y + dy[i];
					if (cdx < 0 || cdy < 0 || cdy >= N || cdx >= N)
					{
						continue;
					}
					map[cdx][cdy].push_back(1);
					
				}
			}
		}
		
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tree[i][j] = tree[i][j] + winter[i][j];
		}
	}


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> winter[i][j];
			tree[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		map[x-1][y-1].push_back(z);
		//pos.push({ x-1, y-1 });
	}
	for (int k = 0; k < K; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j].size() > 0)
				{
					pos.push({ i,j });
				}
			}
		}
		simul(map);
	}
	int ans = 0;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < map[i][j].size();k++)
			{
				if (map[i][j][k] != 0) 
				{
					ans += 1;
				}
			}
			
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << tree[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < map[i][j].size();k++)
			{
				cout << i << "¿Í" << j << ":" << map[i][j][k] << "  ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	cout << ans;
}