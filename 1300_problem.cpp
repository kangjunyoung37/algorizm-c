#include<iostream>
#include<algorithm>
using namespace std;
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);


	int N, Start, End, K, result;

	cin >> N;
	cin >> K;
	Start = 1;
	End = K;

	while (Start <= End)
	{
		int middle = (End + Start) / 2;
		long long sum = 0;
		for (int i = 1; i <= N; i++)
		{
			sum += min(N, middle / i);
		}

		if (sum < K)
		{
			Start = middle + 1;
		}
		else
		{
			result = middle;
			End = middle - 1;
		}
	}
	cout << result;

}