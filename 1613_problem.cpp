#include<iostream>
using namespace std;

int map[401][401];
int n, k;
void floyd() {
	for (int m = 1; m <= n; m++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}
				
				if (map[i][m] == map[m][j] && map[i][m] != 0)
				{
					map[i][j] = map[i][m];
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1;j <= n; j++)
		{
			map[i][j] = 0;
		}
	}
	for (int i = 0;i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = -1;
		map[b][a] = 1;

	}
	floyd();
	//for (int i = 0;i < n; i++)
	//{
	//	for (int j = 0;j < n; j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//} 출력 확인
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << map[x][y] << "\n";

	}

}