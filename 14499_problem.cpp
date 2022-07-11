#include<iostream>
#define MAX_V 20
#define MAX_C 1000
int map[MAX_V][MAX_V];
using namespace std;
int N, M, X, Y, K;
int dice[6] = { 0,0,0,0,0,0 };

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0 };
int under = 1;
int temp;

void moveleft()
{
	temp = dice[0];
	dice[0] = dice[3];
	dice[3] = dice[5];
	dice[5] = dice[2];
	dice[2] = temp;

}
void moveright()
{
	temp = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[3];
	dice[3] = temp;
}
void moveup()
{
	temp = dice[0];
	dice[0] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[4];
	dice[4] = temp;

}
void movedown()
{
	temp = dice[0];
	dice[0] = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[1];
	dice[1] = temp;

}
void simul(int x) {
	x = x - 1;
	int cdx = X + dx[x];
	int cdy = Y + dy[x];
	if (cdx < 0 || cdy < 0 || cdx >= N || cdy >= M)
	{
		return;
	}
	X = cdx;
	Y = cdy;
	switch (x)
	{
	case 0:
		moveright();
		break;
	case 1:
		moveleft();
		break;
	case 2:
		moveup();
		break;
	case 3:
		movedown();
		break;
	}

	if (map[cdx][cdy] == 0)
	{
		map[cdx][cdy] = dice[0];
	}
	else
	{
		dice[0] = map[cdx][cdy];
		map[cdx][cdy] = 0;
	}
	cout << dice[5] << "\n";

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> X >> Y >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int command;
		cin >> command;
		simul(command);
	}

}