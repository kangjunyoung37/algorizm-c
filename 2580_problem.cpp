#include<iostream>
using namespace std;

int map[10][10];
bool vertical[10][10];
bool horizontal[10][10];
bool box[10][10];

int checkbox(int x, int y)
{
	return (x / 3) * 3 + (y / 3);
}
void printresult()
{
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
void dfs(int num)
{
	if (num == 81)
	{
		printresult();
		exit(0);
	}

	int x = num / 9;
	int y = num % 9;
	if (map[x][y] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (!vertical[y][i] && !horizontal[x][i] && !box[checkbox(x, y)][i])
			{
				vertical[y][i] = horizontal[x][i] = box[checkbox(x, y)][i] = true;
				map[x][y] = i;
				dfs(num + 1);
				vertical[y][i] = horizontal[x][i] = box[checkbox(x, y)][i] = false;
				map[x][y] = 0;
			}
		}
	}
	else
	{
		dfs(num + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
			vertical[j][map[i][j]] = true;
			horizontal[i][map[i][j]] = true;
			box[checkbox(i, j)][map[i][j]] = true;
		}
	}
	dfs(0);

}