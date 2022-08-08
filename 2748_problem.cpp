#include<iostream>

using namespace std;
long long d[91];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	d[0] = 0;
	d[1] = 1;
	
	for (int i = 2; i < 91; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}
	int N;
	cin >> N;
	cout << d[N];

}