#include<iostream>
#include<queue>
#include<string>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visit[51][51];
string map[51];
int N;

void func(int x, int y)
{
	visit[x][y] = 0;

	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cdx = dx[i] + cx;
			int cdy = dy[i] + cy;
			if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= N)
			{
				continue;
			}
			if (map[cdx][cdy] == '1' )
			{
				if (visit[cdx][cdy] == -1 || visit[cdx][cdy] > visit[cx][cy])
				{
					visit[cdx][cdy] = visit[cx][cy];
					q.push({ cdx,cdy });

				}


			}
			else if (map[cdx][cdy] == '0')
			{
				if (visit[cdx][cdy] == -1 || visit[cdx][cdy] > visit[cx][cy] + 1)
				{
					visit[cdx][cdy] = visit[cx][cy] + 1;
					q.push({ cdx,cdy });
				}
				
			
			}
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	string a;
	for (int i = 0; i < N; i++)
	{
			cin >> map[i];
			for (int j = 0; j < N; j++)
			{
				visit[i][j] = -1;
			}
	}
	func(0, 0);
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << visit[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	cout << visit[N - 1][N - 1];
}