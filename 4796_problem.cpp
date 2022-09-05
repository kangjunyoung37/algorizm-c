#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);cout.tie(0);
	int cnt = 1;
	while (1)
	{
		int L, P, V;
		cin >> L >> P >> V;
		int sum = 0;
		if (L == 0 && P == 0 && V == 0)
		{
			break;
		}
		sum += (V / P) * L;
		if (V % P > L)
		{
			sum += L;
		}
		else
		{
			sum += (V % P);
		}
		cout << "Case" << " " << cnt << ":" << " " << sum <<"\n";
		cnt += 1;
	}
}