#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a,T;
	cin >> T;
	if (T % 10 != 0)
	{
		cout << -1;
	}
	else
	{
		a = T / 300;
		T = T % 300;
		cout << a << " ";
		a = T / 60;
		T = T % 60;
		cout << a << " ";
		a = T / 10;
		T = T % 10;
		cout << a << " ";
	}
	return 0;
}