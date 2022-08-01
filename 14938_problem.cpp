#include<iostream>
#include<algorithm>

using namespace std;
#define MAX 987654321

int map[101][101];
int n, m, r;
int item[101];
void floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				map[i][j] = min(map[i][k] + map[k][j], map[i][j]);				
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = MAX;
		}
	}
	for (int i = 1;i <= n; i++)
	{
		cin >> item[i];
		map[i][i] = 0;
	}
	for (int i = 0; i < r; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x][y] = d;
		map[y][x] = d;

	}
	floyd();
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= n; j++)
	//	{
	//		if (map[i][j] == MAX)
	//		{
	//			cout << 0 << " ";
	//			continue;
	//		}
	//		cout << map[i][j] << " ";

	//	}
	//	cout << "\n";
	//}
	int result = 0;
	
	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		for (int j = 1; j <= n; j++)
		{

			if (m >= map[i][j])
			{
				temp += item[j];
			}
			
		}
		result = max(result,temp); 

	}
	cout << result;
}