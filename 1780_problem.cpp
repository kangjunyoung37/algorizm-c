#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long N;
	cin >> N;
	if (N == 1)
	{
		cout << 1;
		return 0;
	}
	int i = 1;
	long long sum = 0;
	while (1)
	{
		if (sum == N)
		{
			cout << i - 1;
			break;
		}
		if (sum > N)
		{
			cout << i - 2;
			break;
		}
		sum += i;
		i++;
	}
}