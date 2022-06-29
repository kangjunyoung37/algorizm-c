#include<iostream>
using namespace std;

int n, m;
int result[10] = { 0, };
bool visit[10] = { false , };

void dfs(int before, int x)
{
	if (x == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << result[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = before; i <= n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			result[x] = i;
			dfs(i+1, x +1);
			visit[i] = false;//백트래킹
		}
	}



}
int main() {
	cin >> n >> m;

	dfs(1, 0);

	return 0;

}