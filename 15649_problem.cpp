#include<iostream>
using namespace std;


int n, m;
int result[10] = {0,};
bool visit[10];
void dfs(int x) {

	if (x == m)
	{
		for (int i = 0; i < m; i++)//x �� m �̶� �������� ���
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])//�湮üũ
		{
			visit[i] = true;
			result[x] = i;
			dfs(x + 1);
			visit[i] = false;//��Ʈ��ŷ 
		}
		
	}

}
int main() {


	cin >> n >> m;
	dfs(0);

	return 0;
	
}