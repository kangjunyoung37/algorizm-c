#include<iostream>
#include<tuple>
using namespace std;

int T[16];
int M[16];
int dp[16];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> M[i];
	}
	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		for (int j = 1; j <= i; j++)
		{
			int day = i - j + 1;
			if (day >= T[j])
			{
				temp = max(temp, M[j]);
			}
		}
		M[i+1] += temp;
		dp[i] = temp;

	}
	cout << dp[N];

}