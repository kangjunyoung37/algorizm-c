#include<iostream>

using namespace std;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int wine[10001] = {0 , };
	int dp[10001] = {0 , };
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> wine[i];
	}
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(dp[i - 3] + wine[i - 1], dp[i - 2]) + wine[i];
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[N];
}