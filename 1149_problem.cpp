#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int dp[1001][3];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + dp[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + dp[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + dp[i][2];
	}
	cout << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);

}