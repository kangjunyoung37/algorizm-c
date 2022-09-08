#include<iostream>
using namespace std;


long long d[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;
	cin >> N;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}
	//cout << d[N];
	int result = (d[N] % 15746);
	cout << result;
	
}