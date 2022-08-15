#include<iostream>
#define MAX_D 1000000000
using namespace std;

int d[101][10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for (int i = 1; i < 10; i++)
	{
		d[1][i] = 1;
	}
	int n;
	cin >> n;
	for (int i = 2; i <= n;i++)
	{
		d[i][0] = d[i - 1][1] % MAX_D;
		for (int j = 1; j < 9; j++)
		{
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1])%MAX_D;
		}
		d[i][9] = d[i - 1][8] % MAX_D;
	}
	long long result = 0;
	for (int i = 0; i < 10; i++)
	{
		//cout << d[n][i] << " ";
		result += d[n][i];
	}
	cout << result % MAX_D;
}