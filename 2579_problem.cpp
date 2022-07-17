#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h[302];
	int d[302];

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> h[i];
	}

	d[1] = h[1];
	d[2] = h[1] + h[2];
	for (int i = 3; i <= N; i++)
	{
		d[i] = max(d[i - 2] + h[i], d[i - 3] + h[i] + h[i - 1]);
	}
	/*for (int i = 0; i <= N; i++)
	{
		cout << d[i] << " " << "\n";
	}*/
	cout << d[N];

	

}