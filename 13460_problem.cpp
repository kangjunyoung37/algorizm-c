#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
char map[11][11];
int dx[4] = { -1,1,0,0 };//»óÇÏÁÂ¿ì
int dy[4] = { 0,0,-1,1 };
int result;
int visit[11][11][11][11];

int Rx, Ry, Bx, By;
bool is = false;
queue<tuple<int, int, int, int, int>> q;
void move(int Rx ,int Ry,int Bx,int By, int cnt)
{
	
	q.push({ Rx, Ry, Bx, By, cnt });


	while (!q.empty())
	{
		int QRx = get<0>(q.front());
		int QRy = get<1>(q.front());
		int QBx = get<2>(q.front());
		int QBy = get<3>(q.front());
		int totalcnt = get<4>(q.front());
		visit[QRx][QRy][QBx][QBy] = 1;
		q.pop();

		if (totalcnt > 10)
		{
			break;
		}
		if (map[QRx][QRy] == 'O')
		{
			is = true;
			result = totalcnt;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int Rdx = QRx;
			int Rdy = QRy;
			int Bdx = QBx;
			int Bdy = QBy;

			while (true)
			{
				if (map[Rdx + dx[i]][Rdy+dy[i]] == '.')
				{
					Rdx += dx[i];
					Rdy += dy[i];
				}
				else if (map[Rdx + dx[i]][Rdy + dy[i]] == 'O')
				{
					Rdx += dx[i];
					Rdy += dy[i];
					break;
				}
				else
				{
					break;
				}
			}

			while (true)
			{
				if (map[Bdx + dx[i]][Bdy+dy[i]] == '.')
				{
					Bdx += dx[i];
					Bdy += dy[i];
				}

				else if (map[Bdx + dx[i]][Bdy + dy[i]] == 'O')
				{
					Bdx += dx[i];
					Bdy += dy[i];
					break;
				}
				else
				{
					break;
				}
			}

			if (map[Bdx][Bdy] == 'O')
				continue;
			if (Bdx == Rdx && Bdy == Rdy)
			{
				switch (i)
				{
				case 0:QRx > QBx ? Rdx++ : Bdx++;
					break;
				case 1:QRx < QBx ? Rdx-- : Bdx--;
					break;
				case 2:QRy > QBy ? Rdy++ : Bdy++;
					break;
				case 3:QRy < QBy ? Rdy-- : Bdy--;
					break;

				}
			}
			if (visit[Rdx][Rdy][Bdx][Bdy] == 0)
			{
				q.push({ Rdx,Rdy,Bdx,Bdy,totalcnt + 1 });
			}
		
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string A;
		cin >> A;
		for (int j = 0; j < M; j++)
		{
			if (A[j] == 'R')
			{
				map[i][j] = '.';
				Rx = i;
				Ry = j;
			}
			else if (A[j] == 'B')
			{
				map[i][j] = '.';
				Bx = i;
				By = j;
			}
			else
			{
				map[i][j] = A[j];
			}
		}
	}

	move(Rx, Ry, Bx, By, 0);
	if (is)
	{
		cout << result;
	}
	else
	{
		cout << -1;
	}
}