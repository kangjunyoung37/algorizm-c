#include<iostream>
#include<vector>

#define MAX 105
using namespace std;

vector<int> a[MAX];
int visit[MAX];
int cnt = -1;
void dfs(int x)
{
	cnt++;
	visit[x] = 1;
	for (int i = 0; i < a[x].size();i++)
	{
		if (!visit[a[x][i]])//방문한게 아니라면
		{		
			int next = a[x][i];
			dfs(next);//dfs실행
		}

	}
	
	

}
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int com;
	cin >> com;
	int warm;
	cin >> warm;
	fill(&visit[0], &visit[com], 0);
	for (int i = 0; i < warm; i++)
	{
		int start, end;
		cin >> start >> end;
		a[start].push_back(end);
		a[end].push_back(start);
	}
	dfs(1);
	cout << cnt;



}