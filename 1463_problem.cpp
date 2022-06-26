#include<iostream>
#include<vector>
using namespace std;
void find(int n, vector<int>& dp) //다이나믹 프로그래밍
{
	//1부터 차례대로 올라가면서 n까지 최소 횟수를 구한다
	dp[n] = dp[n - 1] + 1;
	if (n % 2 == 0)
	{
		dp[n] = min(dp[n / 2] + 1,dp[n]);
	}
	if (n % 3 == 0)
	{
		dp[n] = min(dp[n / 3] + 1,dp[n]);
	}
}
int main() {

	int n;
	cin >> n;

	vector<int> dp(n+1);

	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i <= n ; i++)
	{
		find(i,dp);
	}
	cout << dp[n];

	return 0;


}