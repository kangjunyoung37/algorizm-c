#include<iostream>
#include<vector>
using namespace std;

int map[101][101];
int N;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int x, y, d, g , cnt = 0;
vector<int> Direct;



void drangoncureve()
{
	
	int ds = Direct.size() ;
	for (int i = ds -1 ; i >= 0; i--)
	{
		int a = (Direct[i] + 1) % 4;
		x = x + dx[a];
		y = y + dy[a];
		map[x][y] = 1;
		Direct.push_back(a);
	}
}

void CountSquare()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1)
			{
				cnt += 1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		
		cin >> y >> x >> d >> g;
		Direct.clear();
		map[x][y] = 1;
		x = x + dx[d];
		y = y + dy[d];
		map[x][y] = 1;
		Direct.push_back(d);
		for (int j = 0; j < g; j++)
		{
			drangoncureve();
		}
	}
	CountSquare();
	cout << cnt;

}