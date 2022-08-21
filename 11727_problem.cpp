#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int d[1001];
	d[1] = 1;
	for (int i = 2; i < 1000; i++)
	{
		if (i % 2 == 1)
		{
			d[i] = (d[i - 1] * 2) - 1;
		}
		else
		{
			d[i] = (d[i - 1] * 2) + 1;
		}
	}
	int n;
	cin >> n;
	int ans = d[n] % 10007;
	cout << ans;

}