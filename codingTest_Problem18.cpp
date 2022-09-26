#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visit[100][100];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<vector<int>> maps;
	maps.push_back({ 1,0,1,1,1 });
	maps.push_back({ 1,0,1,0,1 });
	maps.push_back({ 1,0,1,1,1 });
	maps.push_back({ 1,1,1,0,1 });
	maps.push_back({ 0,0,0,0,1 });

	queue < pair<int, int>> q;
	visit[0][0] = 1;
	q.push({ 0,0 });
	int x, y;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cdx = x + dx[i];
			int cdy = y + dy[i];
			if (cdx < 0 || cdy < 0 || cdx >= maps.size() || cdy >= maps[0].size())
			{
				continue;
			}
			if (maps[cdx][cdy] == 1 && visit[cdx][cdy] == 0)
			{
				visit[cdx][cdy] = visit[x][y] + 1;
				q.push({ cdx,cdy });
			}
		}
	}
	
	/*for (int i = 0; i < maps.size(); i++)
	{
		for (int j = 0; j < maps[0].size(); j++)
		{
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << visit[maps.size() - 1][maps[0].size() - 1];

}