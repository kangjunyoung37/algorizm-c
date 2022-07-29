#include<iostream>
#include<vector>
using namespace std;


int Parent[101];
bool visit[101];
vector<int> map[101];

void bfs(int start, int cnt)
{
	Parent[start] = cnt;
	visit[start] = true;
	for (int i = 0; i < map[start].size(); i++)
	{
		if (!visit[map[start][i]])
		{
			bfs(map[start][i], cnt + 1);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		Parent[i] = 0;
		visit[i] = false;
	}
	int targetNUM1, tartgetNUM2;
	cin >> targetNUM1 >> tartgetNUM2;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x].push_back(y);
		map[y].push_back(x);
	}
	//for (int i = 0; i <= N; i++)
	//{
	//	for (int j = 0; j < map[i].size(); j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	bfs(targetNUM1, 0);
	/*for (int i = 1; i <= N; i++)
	{
		cout << Parent[i] << " ";
	}*/
	if (Parent[tartgetNUM2] == 0)
	{
		cout << -1;
		return 0;
	}
	cout << Parent[tartgetNUM2];



}