#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	long long d[91];
	d[0] = 1;
	d[1] = 1;
	d[2] = 1;
	for (int i = 3;i <= 90; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}
	int N;
	cin >> N;
	cout << d[N];
}