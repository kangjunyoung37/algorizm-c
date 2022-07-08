#include<iostream>
#define MAX_V 502
using namespace std;
int map[MAX_V][MAX_V], degree[MAX_V];
int N, M;
int cnt = 0;
void floyd() {


	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (map[i][k] && map[k][j])//i에서 k로 가는 경로와 k에서 j로 가는 경로가 있다면
				{
					map[i][j] = 1;//i에서 j로 가는 경로가 있다.
				}
			}



}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;

	}
	floyd();
	/*for (int i = 1; i <=N; i++)
	{
		for (int j = 1; j <= N;j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N;j++)
		{
			if (map[i][j] == 1)
			{
				degree[i]++;
				degree[j]++;
			}
		}

	}

	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == (N - 1))
		{
			cnt++;
		}
	}
	cout << cnt;

}