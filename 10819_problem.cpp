#include<iostream>

using namespace std;
int N;
int num[9];
bool visit[9];
int result[9];
int ans = 0;
void fund(int x)
{
	if (x == N)
	{
		int sum = 0;
		for (int i = N-1; i >= 1; i--)
		{
			sum += abs(result[i] - result[i - 1]);
		}
		if (ans < sum)
		{
			ans = sum;
		}
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (visit[i] == true)
		{
			continue;
		}
		visit[i] = true;
		result[x] = num[i];
		fund(x + 1);
		visit[i] = false;
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	fund(0);
	cout << ans;
}