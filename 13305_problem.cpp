#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int N;
	cin >> N;
	long long distance[100001];
	long long prices[100001];
	for (int i = 1; i < N;i++)
	{
		cin >> distance[i - 1];

	}
	for (int i = 0; i < N; i++)
	{
		cin >> prices[i];
	}
	long long result = 0;
	long long price = prices[0];
	for (int i = 0; i < N-1;i++)
	{
		if (price > prices[i])
		{
			price = prices[i];
		}
		result  +=  price * distance[i];
	}


	cout << result;
}