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
				if (graph[i][k] && graph[k][j])//i���� k�� ���� ��ο� k���� j�� ���� ��ΰ� �ִٸ�
				{
					graph[i][j] = 1;//i���� j�� ���� ��ΰ� �ִ�.
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