#include<iostream>
#include<algorithm>
#define MAX_C 102
#define INF 12345678
using namespace std;

int map[MAX_C][MAX_C];
int n;
void floyd() {
	for (int m = 1; m <=n; m++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}
				map[i][j] = min(map[i][j], map[i][m] + map[m][j]);
		
			}
		}
	}
}

int main() {
	cin >> n;
	int bus;
	cin >> bus;


	for(int i = 1; i <=n; i ++)
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = INF;
		}

	for (int i = 0; i < bus; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		map[a][b] = min(map[a][b], c);
	}
	
	floyd();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == INF)
			{
				cout << 0 << " ";
				continue;
			}
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
