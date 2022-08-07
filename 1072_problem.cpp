#include<iostream>

using namespace std;
long double  X, Y;

long double Start = 1;
long double End;
long long ans = 10e9;
void binary(int result)
{
	End = X;
	while (Start <= End)
	{
		long long middle = (Start + End) / 2;

		long long x = X + middle;
		long long y = Y + middle;
		long long temp = ((Y + middle) / (X + middle)) * 100;
		if (temp - result > 1)
		{
			End = middle - 1;
			if (ans > middle)
			{
				ans = middle;
			}
		}
		if (temp-result < 1)
		{
			Start = middle + 1;
		}
		if (temp-result == 1)
		{
			End = middle - 1;
			if (ans > middle)
			{
				ans = middle;
			}
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> X >> Y;


	long long result;
	result =(Y / X) * 100;
	//cout << result;
	if (result >= 99)
	{
		cout << -1;
		return 0;
	}
	binary(result);

	cout << ans;
}