#include<iostream>
#include<vector>
using namespace std;

int W[11][11];
int visit[11],N;
int ans[11];
int result = 2100000000;
int Start;
void func(int x,int prev,int distance)
{
	if (x == N)
	{
		if (W[prev][Start] > 0)
		{
			result = min(distance + W[prev][Start], result);
		}
		return;
	}
	for (int i = 0; i < N ; i++)
	{
		if (visit[i])
			continue;
		if (W[prev][i] == 0)
			continue;
		ans[x] = i;
		visit[i] = 1;
		func(x + 1,i,distance + W[prev][i]);
		visit[i] = 0;
	}


}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		visit[i] = 1;
		Start = i;
		func(1,i,0);
		visit[i] = 0;
	}


	if (result == 2100000000)
	{
		cout << 0;
	}
	else
	{
		cout << result;
	}

}