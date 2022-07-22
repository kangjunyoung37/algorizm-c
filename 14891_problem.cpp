#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int gear[4][3] = { {2,6,0},{2,6,0},{2,6,0},{2,6,0} };//기어의 오른쪽에 몇번이 들어가 있는지 체크
string A[4]; //기어정보
int rot[4] = { 0,0,0,0 };//회전정보
void loate(int a, int direction) 
{
	if (direction == 1)
	{
		gear[a][0] = (gear[a][0] + 7) % 8;
		gear[a][1] = (gear[a][1] + 7) % 8;
		gear[a][2] = (gear[a][2] + 7) % 8;
	}

	else if (direction == -1)
	{
		gear[a][0] = (gear[a][0] + 1) % 8;
		gear[a][1] = (gear[a][1] + 1) % 8;
		gear[a][2] = (gear[a][2] + 1) % 8;
	}

}

void simul(int num, int direct)
{
	rot[num] = direct;
	for (int i = num ; i < 4; i++)
	{
		if (i == 3)
		{
			break;
		}
		if (A[i][gear[i][0]] == A[i + 1][gear[i+1][1]])
		{
			break;
		}
		if (rot[i] == 1)
		{
			rot[i + 1] = -1;
		}


		else if (rot[i] == -1)
		{
			rot[i + 1] = 1;
		}

	}
	for (int i = num; i > -1; i--)
	{
		if (i == 0)
		{
			break;
		}
		if (A[i][gear[i][1]] == A[i - 1][gear[i-1][0]])
		{
			break;
		}
		if (rot[i] == 1)
		{
			rot[i - 1] = -1;
		}
		else if (rot[i] == -1)
		{
			rot[i - 1] = 1;
		}
	}
}

void rotclear() {
	for (int i = 0;i < 4; i++)
	{
		rot[i] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> A[i];
	}
	int N; 
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		
		int G, direct;
		cin >> G >> direct;
		simul(G - 1, direct);
		for (int i = 0; i < 4; i++)
		{

			loate(i, rot[i]);
		}
		rotclear();
	}
	for (int i = 0; i < 4; i++)
	{
		if ( A[i][gear[i][2]] == '1')
		{
			result += pow(2, i);
		}
	}
	cout << result;

}