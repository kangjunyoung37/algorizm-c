#include<iostream>
#include<algorithm>

#define MAX 105
#define INF 12345678

using namespace std;
int n;
int graph[MAX][MAX];

void floyd() {

	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j++)
			{
				if (graph[i][k] && graph[k][j])//i에서 k로 가는 경로와 k에서 j로 가는 경로가 있다면
				{
					graph[i][j] = 1;//i에서 j로 가는 경로가 있다.
				}
			}
	return;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=n; j++)
		{
			cin >> graph[i][j];
		}
	}
	floyd();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	

}