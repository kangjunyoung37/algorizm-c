#include<iostream>
using namespace std;

int map[31][31];
int main()
{
	ios_base::sync_with_stdio(false);

	for (int i = 1; i < 31;i++)
	{
		map[1][i] = i;
		map[i][i] = 1;
	}
	for (int i = 2; i < 31; i++)
	{
		for (int j = i+1; j < 31; j++)
		{
			map[i][j] = map[i - 1][j - 1] + map[i][j - 1];
		}
	}
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << map[x][y] << "\n";
	}

}