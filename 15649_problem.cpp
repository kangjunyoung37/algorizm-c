#include<iostream>
using namespace std;


int n, m;
int result[10] = {0,};
bool visit[10];
void dfs(int x) {

	if (x == m)
	{
		for (int i = 0; i < m; i++)//x 가 m 이랑 같아지면 출력
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])//방문체크
		{
			visit[i] = true;
			result[x] = i;
			dfs(x + 1);
			visit[i] = false;//백트래킹 
		}
		
	}

}
int main() {


	cin >> n >> m;
	dfs(0);

	return 0;
	
}