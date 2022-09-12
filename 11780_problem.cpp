#include<iostream>
#include<vector>
#define INF 987654321
using namespace std;

int N,M;
int map[101][101];
int visit[101][101];
vector<int> V;
void floyd()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (map[i][j] > map[i][k] + map[k][j])
				{
					map[i][j] = map[i][k] + map[k][j];
					visit[i][j] = k;
				}
			}
		}
	}
}
void FindRoot(int Start, int End)
{
	if (visit[Start][End] == 0)
	{
		V.push_back(Start);
		V.push_back(End);
		return;
	}
	FindRoot(Start, visit[Start][End]);
	V.pop_back();
	FindRoot(visit[Start][End], End);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1;j <= N; j++)
		{
			map[i][j] = INF;
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x][y] = min(map[x][y], d);
		//visit[x][y] = x;
	}
	floyd();

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1;j <= N; j++)
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
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1;j <= N; j++)
		{
			if (map[i][j] == INF)
			{
				cout << 0 ;
			}
			else
			{
				V.clear();
				FindRoot(i, j);
				cout << V.size() << " ";
				for (int k = 0; k < V.size();k++)cout << V[k] << " ";
			}
			cout << "\n";
		}

	}


}