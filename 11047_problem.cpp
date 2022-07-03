#include<iostream>
#include<vector>
using namespace std;

vector<int> coins;
int main()
{
	int N, K;
	cin >> N >> K;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}
	for (int i = coins.size() - 1; i >= 0; i--)
	{

		cnt += K / coins[i];
		K %= coins[i];
		
	}

	cout << cnt;
	return 0;

}